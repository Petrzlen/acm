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

//t, si, pi 
int B[12345][32][32];

vector<PII> solve(vector<PII>& P, vector<PII>& W, int n){
  //cout << "===solve " << n << endl;
  //REP(i, P.size()) cout << "  " << P[i].first << ":" << P[i].second << endl;

  set<int> S;
  REP(i, W.size()) {
    int s=0;
    while(S.size() < n && W[i].first-1-s >= W[i].second){
      S.insert(W[i].first-1-s);
      s++; 
    }
  }
  if(S.size() < n) return vector<PII>(); 
  
  vector<int> D; 
  for(set<int>::iterator iter = S.begin(); iter != S.end() ; iter++){
    D.push_back(*iter - D.size()); 
    //cout << "t: " << D[D.size() - 1] << endl;
  }
  
  REP(i, 12345) REP(j, n+1) REP(k, P.size()+1) B[i][j][k] = -1;
  REP(i, P.size()) B[0][0][i]=0; 
  
  REP(pi, P.size()) for(int si=n; si>=1 ; si--) for(int t=D[si-1]; t>=0; t--){
    B[t][si][pi+1] = B[t][si][pi]; 
    
    int ti= P[pi].first;
    if(t-ti < 0) continue; 
    
    int b = B[t-ti][si-1][pi]; 
    if(b >= 0){
      int bnew = b + P[pi].second; 
      if(bnew > B[t][si][pi+1]){
        B[t][si][pi+1] = bnew;
      }
      
      //cout << "pi=" << pi << " si=" << si << " t=" << t << " bold=" << b << " bnew=" << bnew << endl;
    }
  }
  
  //REP(i, 12345) REP(j, n+1) REP(k, P.size()+1) if(B[i][j][k]>=0) cout << i << "," << j << "," << k << ":" << B[i][j][k] << endl;
  
  vector<PII> result;
  int mv=0;
  PII mi(0,0);  
  int p=0; 
  REP(i, 12345) REP(j, n+1) REP(k, P.size()+1) if(B[i][j][k]>mv) {
    mv=B[i][j][k];
    mi = PII(i, j); 
    p = k; 
  }
  
  while(mi.first >= 0 && mi.second > 0){
    while(p>0 && B[mi.first][mi.second][p-1] >= B[mi.first][mi.second][p]) p--; 
    p--; 
    
    //cout << "  " << mi.first << "," << mi.second << "," << p << ":" << B[mi.first][mi.second][p] << endl;
     
    result.push_back(PII(D[n-1-result.size()], p)); 
    mi.first -= P[p].first; 
    mi.second--; 
  }
  
  return result; 
}

int main(){
  int N, M;
  cin >> N >> M;
  
  //time, score
  vector<PIII> P(N, PIII(PII(0,0), 0)); 
  REP(i, N) cin >> P[i].first.second >> P[i].first.first; 
  REP(i, N) P[i].second = i+1; 
  
  //to, from 
  vector<PII> W(M, PII(0,0)); 
  REP(i, M) cin >> W[i].second >> W[i].first; 
  
  sort(P.begin(), P.end()); 
  sort(W.begin(), W.end(), greater<PII>()); 
  
  vector<PII> Q;
  REP(i, P.size()) Q.push_back(P[i].first); 
  
  vector<PII> result; 
  int bsum = 0; 
  REP(i, N){
    vector<PII> r = solve(Q, W, i+1);
    int sum = 0; 
    REP(i, r.size()) sum += Q[r[i].second].second; 
    if(sum > bsum) {
      result = r; 
      bsum = sum; 
    }
  }
  
  reverse(result.begin(), result.end()); 
  cout << bsum << " " << result.size() << endl;
  REP(i, result.size()) cout << P[result[i].second].second << " " << result[i].first + i << endl;
  
  return 0; 
}
