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
LLI INF = 123456789123456789ll; 

LLI check(int b, int k, vector<PII> P){
  int w=0; 
  LLI e=0; 
  REP(i, P.size()) {
    if(b & (1 << i)) {
      w += 1; 
      e += P[i].second; 
    }
    else {
      P[i].first += 2; // when same, Manao lost 
    }
  }
  
  P.push_back(PII(w, INF));
  sort(P.begin(), P.end(), greater<PII>());
  
  /*
  cout << "======" << endl;
  REP(i, P.size()) {
    cout << P[i].first << ":" << P[i].second << endl;
  }
  cout << "  e=" << e << endl; */ 
  
  REP(i, P.size()) if(P[i].second == INF && i < k) return e; 
  return INF; 
}

int main(){
  int N, K; 
  cin >> N >> K; 
  
  vector<PII> P(N, PII(0,0)); 
  REP(i, N) cin >> P[i].first >> P[i].second; 
  
  LLI result = INF; 
  REP(i, (1<<N)) result = min(result, check(i, K, P)); 
  cout << ((result == INF) ? -1 : result) << endl;
  
  return 0; 
}
