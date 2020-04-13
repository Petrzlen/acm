// BEWARE! There is a small bug in the code, as it fails on Test #2 and #4
// I've:
//   - tripple checked the <.<= >, >= conditions
//   - used "decimal" instead of double, 64bit instead of 32bit
//   - tried non-recursive stop orders (no affect)
//   - all DASSERT pass.

// Contains class Market, designed to execute MARKET, LIMIT, STOP and CANCEL orders.
// Implementation uses priority queues (heaps) for getting the "best" available
// buy/sell limit/stop orders to match the incomming order.
// This makes one transaction in K * log(N) complexity, where K is #matched orders.
#include <map>
#include <set>
#include <list>
#include <cfloat>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define DEBUG 0
// Note: For DEBUG == 0 it will be removed by the compiler.
#define DASSERT(cond, message) \
if(DEBUG) {if(!(cond)) {cerr << __LINE__ << ": " << message << endl;} }
// #define DASSERT(cond, message) if (!(cond)) {int* a = new int(); delete a; *a = 42;}

typedef long long int LLI;

namespace voleon {
   
// TODO move this to order.h
typedef unsigned long long int OrderId;
    
enum OrderType {
    MARKET = 1,
    LIMIT = 2,
    STOP = 3,
    CANCEL = 4
};
const string kMarket = "market";
const string kLimit = "limit";
const string kStop = "stop";
const string kCancel = "cancel";

enum TradeType {
    BUY = 1,
    SELL = 2
};
const string kBuy = "buy";
const string kSell = "sell";
  
// Main purpose of OrderStatus is to say the order was cancelled and therefore
// should be ignored. Other states are for debugging purposes.
enum OrderStatus {
    NONE = 0,
    LIVE = 1,
    CANCELLED = 2
};

// TODO: Maybe a more robust design is to have Order part of the Market class.
// TODO: It would be OOPer to have get_ and set_ methods.
class Order {
 public:
    OrderId id_ = 0;
    LLI amount_ = 0;
    LLI price_ = 0;  // In cents.
    OrderStatus status_ = NONE;
    
    // Both order_type_ and trade_type_ used only for debug checks.
    // The type is determined by the data container for limit / sell.
    OrderType order_type_;
    TradeType trade_type_;
};

class PQCompareOrdersByPrice {
 public:
    bool operator() (const Order* a, const Order* b) {
        DASSERT(a->trade_type_ == b->trade_type_, a->id_ << ":" << b->id_);
        DASSERT(a->trade_type_ == SELL || a->trade_type_ == BUY, a->id_);
        if (a->price_ != b->price_) {
// As this is used by priority_queue_, true is returned for elements at bottom.
            if (a->trade_type_ == BUY) return a->price_ < b->price_;
            else return a->price_ > b->price_;
        }
        // Older order is executed first.
        return a->id_ > b->id_;
    }
};

class PQCompareOrdersById {
 public:
    bool operator() (const Order* a, const Order* b) {
// As this is used by priority_queue_, true is returned for elements at bottom.
        return a->id_ > b->id_;
    }
};

typedef priority_queue<Order*, vector<Order*>, PQCompareOrdersByPrice> OrderQueueByPrice;
typedef priority_queue<Order*, vector<Order*>, PQCompareOrdersById> OrderQueueById;

bool CompareOrderToQueueTop(const Order* order, const OrderQueueByPrice* queue) {
    if (queue->empty()) return false;
    DASSERT(order->trade_type_ != queue->top()->trade_type_, 
            order->id_ << ":" << queue->top()->id_ << ":" << order->trade_type_);
    // Ignore order->trade_type_ and just use queue->top()->trade_type_.
    return (queue->top()->trade_type_ == BUY) 
             ? queue->top()->price_ >= order->price_
             : queue->top()->price_ <= order->price_;
    // Id is irrelevant.
}

// END TODO move this to order.h
    
struct MinMaxPrice {
    LLI min_price_;  // In cents.
    LLI max_price_;  // In cents.
};
    
namespace {
    // Helper function.
void DeleteAll(OrderQueueByPrice* pq) {
    if (DEBUG) cout << "Queue contains:" << endl;
    while(!pq->empty()) {
        if (DEBUG) cout << " " << pq->top()->id_ << "," << pq->top()->amount_ << endl;
        delete pq->top();
        pq->pop();
    }
}
}  // namespace
    
// TODO unittests (now we use the sample).
class Market {
 public:
    Market() {}
    ~Market() {
        // TODO: In retrospect, maybe orders_ should've owned Order*.
        DeleteAll(&limit_buy_orders_);
        DeleteAll(&limit_sell_orders_);
        DeleteAll(&stop_buy_orders_);
        DeleteAll(&stop_sell_orders_);
    }
    
    // Using the input format, convert it to local format
    // and route the order to specialized functions.
    // Returns status.
    bool AddOrder(
        const string& order_type, const string& trade_type, LLI value1, 
        LLI value2) {
        // TODO unique_ptr would be a safer option.
        Order* order = new Order();
        order->status_ = LIVE;
        
        DASSERT(next_order_id_ < ULONG_MAX, "We are super-popular!")
        order->id_ = next_order_id_++;
        orders_[order->id_] = order;
        
        if (order_type == kCancel){
            DASSERT(value1 < order->id_, order->id_ << ":" << value1)
            RemoveOrder(order);
            CancelOrder(value1);
            return true;
        }
        // ASSUME: order_type != kCancel
        
        // Parse Order depending on type.
        if (trade_type == kBuy) {
            order->trade_type_ = BUY;
        } else if (trade_type == kSell) {
            order->trade_type_ = SELL;
        } else {
            cerr << "Unrecognized trade_type='" << trade_type << "'" << endl;
            return false;
        }
        // TODO: Sanity checking on amount and price, although data is promissed
        //       to be consistent.
        if (order_type == kMarket) {
            DASSERT(order->trade_type_ == BUY || order->trade_type_ == SELL,
                    order->id_)
            order->order_type_ = MARKET;
            order->amount_ = value1;
            order->price_ = GetMarketOrderPrice(order);
            OrderQueueById stop_orders_to_execute;
            ExecuteOrder(order, &stop_orders_to_execute);
            return true;
        }
        if (order_type == kLimit) {
            DASSERT(order->trade_type_ == BUY || order->trade_type_ == SELL,
                    order->id_)
            order->order_type_ = LIMIT; 
            order->amount_ = value1;
            order->price_ = value2;
            OrderQueueById stop_orders_to_execute;
            ExecuteOrder(order, &stop_orders_to_execute);
            return true;
        }
        if (order_type == kStop) {
            order->order_type_ = STOP;
            order->amount_ = value1;
            order->price_ = value2;
            AddStopOrder(order);
            return true;
        }
        cerr << "Unrecognized order_type='" << order_type << "'" << endl;
        return false;
    }
    
 private:
    // Execution life:
    //   1. Try to match with the market.
    //   2. If LIMIT and amount > 0, then add it to limit_*_orders_.
    //   3. Trigger all stop_*_orders_ as MARKET, recursively call ExecuteOrder.
    // Returns status.
    // Preconditions:
    //   - order_type_ in [MARKET, LIMIT]
    //   - trade_type_ in [BUY, SELL]
    //   - order is NOT owned by (limit|stop)_(buy|sell)_orders_.
    // Postconditions: 
    //   - stop_orders.empty()
    //   - order either deleted or owned by Market.
    void ExecuteOrder(Order* order, OrderQueueById* stop_orders) {
        if (DEBUG) cout << "ExecuteOrder id:" << order->id_ << " " << order->trade_type_
                        << " " << order->amount_ << endl;
        DASSERT(order->status_ != NONE, order->id_);
        
        if (order->status_ == CANCELLED) {
            RemoveOrder(order);
            return;
        }
        // Assume order->status_ == LIVE
        
        // 1. Match a BUY order with available SELL orders and vice-versa.
        // TODO CLARIFY: If multiple orders are matched, does the stop order trigger after the earliest one?
        MinMaxPrice mmp = 
            MatchOrder(order, (order->trade_type_ == BUY) ? &limit_sell_orders_ 
                                                          : &limit_buy_orders_);
        
        // 2. Add if LIMIT.
        if (order->order_type_ == LIMIT && order->amount_ > 0) {
            AddLimitOrder(order);
        } else {
            // Nothing to do with MARKET (or previously STOP) / empty LIMIT.
            RemoveOrder(order);
        }
        // Assume: order is not used from now on.
        
        // 3. Some Orders were matched, let's fetch and trigger StopOrders for execution.
        if (mmp.min_price_ <= mmp.max_price_) {
            if (DEBUG) cout << "Trigger " << mmp.min_price_ << " to " << mmp.max_price_ 
                            << endl;
            // First fetch all the eligible STOP Orders to stop_orders.
            // TODO consider refactoring the two while cycles with a lambda condition.
            // It's similar to CompareOrderToQueueTop, consider refactor to MatchQueue.
            while (!stop_buy_orders_.empty() 
                   && stop_buy_orders_.top()->price_ <= mmp.max_price_) {
                stop_orders->push(stop_buy_orders_.top());
                stop_buy_orders_.pop();
            }
            while (!stop_sell_orders_.empty() 
                   && stop_sell_orders_.top()->price_ >= mmp.min_price_) {
                stop_orders->push(stop_sell_orders_.top());
                stop_sell_orders_.pop();
            }
            // Then execute them in historical order.
            while (!stop_orders->empty()) {
                Order* stop_order = stop_orders->top();
                stop_orders->pop();
                // Execute it as MARKET, this can trigger another STOP Orders.
                stop_order->order_type_ = MARKET;
                stop_order->price_ = GetMarketOrderPrice(stop_order);
                 // Also takes care of stop_order->status == CANCELLED.
                ExecuteOrder(stop_order, stop_orders); 
            } 
        }
    }
    // order is NOT deleted, only order->amount is changed.
    // Precondition: order->trade_type_ != queue->top()->trade_type_.
    MinMaxPrice MatchOrder(Order* order, OrderQueueByPrice* queue) {
        MinMaxPrice result = {LLONG_MAX, LLONG_MIN};
        while (order->amount_ > 0 && CompareOrderToQueueTop(order, queue)) {
            Order* matched_order = queue->top();
            if (matched_order->status_ == CANCELLED) {
                queue->pop();
                RemoveOrder(matched_order);
                continue;
            }
            
            LLI volume = min(order->amount_, matched_order->amount_);
            LLI price = matched_order->price_;
            // TODO use some decimal class, it's money.
            printf("match %lld %lld %lld %lld.%02d\n", 
                   order->id_, matched_order->id_, volume, price / 100, price % 100);
            
            // Update state.
            order->amount_ -= volume;
            matched_order->amount_ -= volume;
            if (matched_order->amount_ <= 0) {
                queue->pop();  // queue->top() == matched_order_
                RemoveOrder(matched_order);
            }
            result.min_price_ = min(result.min_price_, price);
            result.max_price_ = max(result.max_price_, price);
        }
        return result;
    }
    
    LLI GetMarketOrderPrice(const Order* order) {
        return (order->trade_type_ == BUY) ? LLONG_MAX : LLONG_MIN;
    }
    void AddLimitOrder(Order* order) {
        DASSERT(order->order_type_ == LIMIT, order->id_);
        if(order->trade_type_ == BUY) {
            limit_buy_orders_.push(order);
        } else {
            limit_sell_orders_.push(order);
        }
    }
    void AddStopOrder(Order* order) {
        DASSERT(order->order_type_ == STOP, order->id_);
        if(order->trade_type_ == BUY) {
            stop_buy_orders_.push(order);
        } else {
            stop_sell_orders_.push(order);
        }
    }
    void CancelOrder(OrderId id) {
        if (DEBUG) cout << "CancelOrder: " << id << endl;
        // May be called to cancel a nonexistent.
        if (orders_.count(id)) {
            orders_[id]->status_ = CANCELLED;
        }
    }
    void RemoveOrder(const Order* order) {
        if (DEBUG) cout << "RemoveOrder: " << order->id_ << endl;
        DASSERT(orders_.count(order->id_), order->id_);  // Shouldn't be called twice.
        if (orders_.count(order->id_)) {
            orders_.erase(order->id_);  // For CANCELLED, it's already done.
            delete order;
        }
    }
    
    // Addressing all the live orders in the market.
    // Order* NOT owned.
    map<OrderId, Order*> orders_;
    OrderId next_order_id_ = 1;
    
    // Order* owned, must delete upon erase.
    OrderQueueByPrice limit_buy_orders_;
    OrderQueueByPrice limit_sell_orders_;
    
    OrderQueueByPrice stop_buy_orders_;
    OrderQueueByPrice stop_sell_orders_;
};
    
}  // namespace voleon

namespace {
    LLI ParseDecimal(const string& str) {
        LLI res = 0;
        for (LLI i = 0; i < str.size() ; ++i) {
            if ('0' <= str[i] && str[i] <= '9') {
                res = res * 10 + (str[i] - '0');
            }
        }
        return res;
    }
}  //namespace

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    voleon::Market market;
    while (!cin.eof()) {
        string str1, str2;
        LLI value1;
        string value2_str;
        cin >> str1;
        if (cin.eof()) break;
        cin >> str2 >> value1 >> value2_str;
        LLI value2 = ParseDecimal(value2_str);
        market.AddOrder(str1, str2, value1, value2);
    }
    return 0;
}
