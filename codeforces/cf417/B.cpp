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
#define INF 4611686018427387904 

typedef long long int LLI;
typedef pair<LLI, LLI> PII; 

int main(){
  LLI N,M,B; 
  cin >> N >> M >> B; 
  
  vector<PII> F(N, PII(0,0)); 
  vector<LLI> P(N, 0); 
  REP(i, N) {
    LLI m; 
    cin >> F[i].second >> F[i].first >> m;
    
    REP(j, m) {LLI x; cin >> x; P[i] |= 1 << (x-1);} 
  }
  
  sort(F.begin(), F.end()); 
  
  vector<LLI> R(1 << M, INF); 
  R[0]=0; 
  LLI r = INF; 
  
  REP(f, F.size()){
    REP(b, (1 << M)) if(R[b] != INF) R[b | P[f]] = min(R[b | P[f]], R[b] + F[f].second); 
    r = min(r, R[(1 << M) - 1] + B * F[f].first); 
  }
  
  cout << ((r==INF)?-1:r) << endl; 
  
  return 0; 
}
