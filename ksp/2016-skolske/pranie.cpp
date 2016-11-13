#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef pair<int, int> PII; 

int main()
{
  //volne miesto
  priority_queue<int> buckets; 
  //velkost -> {ponozky & tricka = 2; inak = 1}
  priority_queue<PII> items; 
  int n, k, x;
  cin >> n >> k;
  REP(i, n) {
    cin >> x;
    items.push(PII(5*x, 2)); 
  }
  REP(i, k) {
    cin >> x;
    buckets.push(x); 
  }
  
  int result = 0;
  while(!items.empty()){
    if(result < 0) break;
  
    PII item = items.top();
    items.pop(); 
    int space = buckets.top();
    if(item.first <= space){
      buckets.pop(); 
      result++; 
    }
    else{
      if(item.second==2){
        int count = item.first/5;
        items.push(PII(count*2,1));
        items.push(PII(count*3,1));
      }
      else{
        result=-1;
      }
    }
  }
 
  if(result<0) cout<<"NIE"<<endl;
  else cout << result << endl;
  
	return 0;
}
