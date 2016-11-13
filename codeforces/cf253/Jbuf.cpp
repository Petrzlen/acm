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
#include <complex> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 
typedef pair<PII, int> PIII; 

#define TM 12345
#define NM 32
//time, count, last_index_used
int B[TM][NM][NM]; 
//time, points
vector<PII> P;
//to, from  
vector<PII> W; 

vector<PII> solve(int n){
  set<int> S;
  int w=0; 
  while(S.size() <= n && w < W.size()){
    int s = 1; 
    while(S.size() <= n && W[w].first-s>=W[w].second) {
      S.insert(W[w].first - s); 
      s++; 
    }
  }
  
  if(S.size() < n) return vector<PII>(); 
  
  vector<int> D; 
  for(set<int>::iterator iter = S.begin() ; iter != S.end() ; iter++) {
    D.push_back(*iter - D.size()); 
  }
  
  REP(i,TM) REP(j, P.size()+2) REP(k, P.size()+2) B[i][j][k] = -1; 
  REP(i, P.size()) B[0][0][i] = 0; 
  
  REP(li, P.size()) for(int ci=1; ci<=n; ci++) for(int ti=D[ci-1]; ti >= 0 ; ti--){
    
  }
}

int main(){
  int N, M;
  cin >> N >> M; 
  
  vector<PIII> Q; 
  REP(i, N) {int a,b; cin>>a>>b; Q.push_back(PIII(PII(b,a),i+1); }
  sort(Q.begin(), Q.end()); 
  REP(i, Q.size()) P.push_back(Q.first); 
    
  REP(i, M) {int a,b; cin>>a>>b; W.push_back(PII(b,a));} 
  sort(W.begin(), W.end(), greater<PII>()); 
  
  vector<PII> R; 
  int b=0; 
  for(int u=1; u<=N; u++) {
    vector<PII> r = solve(u); 
    R = r; 
  }
    
  cout << b << " " << R.size() << endl; 
  REP(i, R.size()) cout << R[i].first << " " << R[i].second << endl;
    
  return 0; 
}
