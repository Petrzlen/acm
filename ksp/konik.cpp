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
#include <functional> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 
typedef pair<int, PII> PIPII; 

#define MAX 2048
int D[MAX][MAX]; 
int M[MAX][MAX]; 

vector<PII> L[MAX]; 
vector<PII> R[MAX]; 
typedef vector<PII>::iterator VPiter; 

//0 <= param < N
//(|fi-ti|==1 || |fj-tj|=1)
//D[fi][fj]>=0
//if(M[fi][fj]>=M[ti][tj]) return; 
inline void skoc(int fi, int fj, int ti, int tj){
  if((fi-ti)*(fi-ti)<=1 && (fj-tj)*(fj-tj)<=1) return; 
  
  D[ti][tj]=max(D[ti][tj], D[fi][fj]+1); 
}

int main(){
  int N;
  int si, sj;
  cin >> N >> si >> sj; 
  REP(i,N) REP(j,N) {
    cin>>M[i][j]; 
    L[i].push_back(PII(M[i][j], j)); 
    R[j].push_back(PII(M[i][j], i)); 
  }
  REP(i, N) sort(L[i].begin(), L[i].end()); 
  REP(j, N) sort(R[j].begin(), R[j].end()); 
  
  REP(i,N) REP(j,N) D[i][j]=-1;
  D[si-1][sj-1]=0; 
  
  vector<PIPII> K;
  REP(i, N) REP(j,N) K.push_back(PIPII(M[i][j], PII(i,j))); 
  sort(K.begin(), K.end()); 
  
  REP(k, K.size()){
    int i=K[k].second.first;
    int j=K[k].second.second;
    
    if(D[i][j]<0) continue; 
    
    int c=0; 
    if(i>0) for(VPiter iter=lower_bound(L[i-1].begin(), L[i-1].end(), PII(M[i][j]+1, 0)); iter != L[i-1].end(); iter++, c++)  skoc(i,j,i-1,iter->second); 
    c=0; 
    if(i<N-1) for(VPiter iter=lower_bound(L[i+1].begin(), L[i+1].end(), PII(M[i][j]+1, 0)); iter != L[i+1].end(); iter++, c++)  skoc(i,j,i+1,iter->second); 
    
    c=0; 
    if(j>0) for(VPiter iter=lower_bound(R[j-1].begin(), R[j-1].end(), PII(M[i][j]+1, 0)); iter != R[j-1].end(); iter++, c++)  skoc(i,j,iter->second,j-1); 
    c=0; 
    if(j<N-1) for(VPiter iter=lower_bound(R[j+1].begin(), R[j+1].end(), PII(M[i][j]+1, 0)); iter != R[j+1].end(); iter++, c++)  skoc(i,j,iter->second,j+1); 
  }
  
  int result = 0;
  REP(i,N) REP(j,N) result = max(result, D[i][j]); 
  cout << result + 1 << endl;
  
  //REP(i,N) {REP(j,N) cout << D[i][j] << " "; cout << endl; } 

  return 0; 
}
