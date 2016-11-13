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
typedef pair<int, int> PII; 

#define MAX 512
int D[512][512];
char P[512][512]; 
bool A[512][512]; 

int solve(){
  REP(i, MAX) REP(j, MAX) P[i][j]='#'; 
  REP(i, MAX) REP(j, MAX) D[i][j]=0;
  REP(i, MAX) REP(j, MAX) A[i][j]=false;
  
  int N, M;
  cin >> N >> M; 
  REP(i, N){
    string s;
    cin >> s;
    REP(j, M) P[i+1][j+1] = s[j]; 
  }
  
  int result = 1; 
  for(int i=N; i>=1; i--){
    for(int j=M; j>=1; j--){
      if(P[i][j]=='#') continue; 
      
      D[i][j] = 1 + max(D[i+1][j], D[i][j+1]); 
      result = max(result, D[i][j]); 
    }
  }
  
  A[1][1] = true; 
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      if(P[i][j]=='#' || (i==1 && j==1)) continue;
      A[i][j] = A[i-1][j] || A[i][j-1]; 
    }
  }
  
  //REP(i, N+2) { REP(j, M+2) cout << D[i][j] << " "; cout << endl;}
  //REP(i, N+2) { REP(j, M+2) cout << A[i][j] << " "; cout << endl;}
  
  for(int i=N; i>=1; i--){
    for(int j=M; j>=1; j--){
      if(!A[i][j]) continue; 
      
      for(int k=j; P[i+1][k]=='.' ; k--) {
        if(P[i+2][k]=='#' || k==j) continue; 
        result = max(result, D[1][1]-D[i][j] + 2 + j-k + D[i+2][k]); 
        //cout << "A["<<i<<","<<j<<"] to ["<<i+2<<","<<k<<"] ("<<D[1][1]-D[i][j]<<"," << D[i+2][k] << ")" << endl;
      }
      for(int k=i; P[k][j+1]=='.' ; k--) {
        if(P[k][j+2]=='#' || k==i) continue;
        result = max(result, D[1][1]-D[i][j] + 2 + i-k + D[k][j+2]); 
        //cout << "B["<<i<<","<<j<<"] to ["<<k<<","<<j+2<<"] ("<<D[1][1]-D[i][j]<<"," << D[k][j+2] << ")" << endl;
      }
    }
  }
  
  return result; 
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }
  return 0; 
}
