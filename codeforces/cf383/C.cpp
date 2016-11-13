#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<LLI, LLI> PII; 

class NODE{
  public:
    LLI implicit; 
    vector<int> childs; 
    vector<PII> added;  //time, value
    vector<int> queries; //time
};

int N, Q;
vector<NODE> G; 
vector<PII> result; //time, value

#define MAX 262144
vector<LLI> T(MAX*2, 0); 

void add(int i, LLI val){
  if(i<1) return; 
  T[i] += val; 
  add(i/2, val); 
}

LLI get(int from, int to, int n=1, int a=0, int b=MAX){
  //cout << "get(" << from << "," << to << "," << n << "," << a <<"," << b << ")" << endl;

  if(b <= a) return 0;
  if(to <= from) return 0; 
  if(to <= a) return 0;
  if(b <= from) return 0; 
  
  if(from <= a && b <= to) return T[n]; 
  
  if(n < MAX){
    int mid = (a+b)/2; 
    return get(from, to, n*2, a, mid) + get(from, to, n*2+1, mid, b); 
  }
}

void solve(int n, int d=0){
  // add add events 
  REP(i, G[n].added.size()) add(MAX + G[n].added[i].first, G[n].added[i].second * ((d%2==0)?1:-1)); 
  
  // resolve queries
  REP(i, G[n].queries.size()) {
    int t = G[n].queries[i]; 
    int v = G[n].implicit + get(0, t) * ((d%2==0)?1:-1); 
    result.push_back(PII(t, v));
    
    //cout << "n=" << n << " t=" << t << " v=" << v << " d=" << d << " get(0,t)=" << get(0,t) << " implicit=" << G[n].implicit << endl;
    //REP(i, 5) cout << "  " << i << ":" << T[MAX+i] << endl;
  }
  
  // call children 
  REP(i, G[n].childs.size()) solve(G[n].childs[i], d + 1); 
  
  // clean up
  REP(i, G[n].added.size()) add(MAX + G[n].added[i].first, -(G[n].added[i].second * ((d%2==0)?1:-1))); 
}

int main(){
  cin >> N >> Q;
  G.resize(N+47); 
  
  REP(i, N) cin >> G[i+1].implicit; 
  
  REP(i, N-1){
    int a,b;
    cin >> a >> b; 
    G[a].childs.push_back(b); 
  }
  
  REP(t, Q){
    int c;
    cin >> c;
    if(c==1) {
      int x, val;
      cin >> x >> val; 
      G[x].added.push_back(PII(t,val)); 
    }
    if(c==2) {
      int x;
      cin >> x;
      G[x].queries.push_back(t); 
    }
  }
  
  solve(1); 
  
  sort(result.begin(), result.end()); 
  REP(i, result.size()) cout << result[i].second << endl;
  
  return 0; 
}











