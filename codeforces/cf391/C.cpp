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

int low(vector<PII>& P, int i, int w){
  while(i+1 < P.size() && P[i+1].first >= w) i += 1; 
  return i; 
}
int up(vector<PII>& P, int i, int w){
  while(i-1 >= 0 && P[i-1].first <= w) i -= 1; 
  return i-1; 
}

LLI check(vector<PII>& P, int w_total, int w_special, int to_incl, int from_excl){
  //cout << "check w_total=" << w_total << " w_special=" << w_special << " from=" << from_excl << " to=" << to_incl << endl; 
  
  if(P.size() < w_total) return INF; 
  if(w_total < w_special) return INF; 
  if((to_incl-from_excl) < w_special) return INF; 
  LLI result = 0; 
  
  vector<PII> Q; 
  vector<bool> F(P.size(), false); 
  for(int i=to_incl; i>from_excl ; i--) Q.push_back(PII(P[i].second, i)); 
  
  sort(Q.begin(), Q.end()); 
  
  REP(i, w_special) {
    result += Q[i].first; 
    F[Q[i].second] = true; 
  }
  
  Q.clear(); 
  REP(i, P.size()) if(!F[i]) Q.push_back(PII(P[i].second, i)); 
  
  sort(Q.begin(), Q.end()); 
  REP(i, (w_total - w_special)) result += Q[i].first; 
  
  //cout << "  result=" << result << endl;
  return result; 
}

int main(){
  int N, K; 
  cin >> N >> K; 
  
  vector<PII> P(N, PII(0,0)); 
  REP(i, N) cin >> P[i].first >> P[i].second; 
  
  if(K > N){
    cout << 0 << endl;
    return 0; 
  }
  
  sort(P.begin(), P.end(), greater<PII>()); 
  
  // a >= b >= (K-1) >= c >= d 
  int w = P[K-1].first; 
  int a=low(P, K-1, w-1); 
  int b=low(P, K-1, w); 
  int c=up(P, K-1, w); 
  int d=up(P, K-1, w+1); 
  
  //cout << "w=" << w << endl;
  //cout << "(a,b,c,d)=" << a << "," << b << "," << c << "," << d << endl;
  
  LLI result = min(check(P, w, a-(K-2), a, c), 
               min(check(P,w+1, b-(K-2), b, d), 
                   check(P, w+2, 0, 0, 0))); 
  cout << ((result == INF) ? -1 : result) << endl; 
}
