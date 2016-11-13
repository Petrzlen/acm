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
typedef pair<int, PII> PIII; 

#define MAX 42 
#define INF 123456789123456789ll 

int main(){
  LLI N; 
  LLI C[MAX][3][3]; 
  LLI orig[3][3]; 
    
  REP(i, 3) REP(j, 3) cin >> orig[i][j]; 
  cin >> N; 
  
  //init c 
  REP(a, MAX) REP(i, 3) REP(j, 3) C[a][i][j] = INF; 
  REP(i, 3) REP(j, 3) C[1][i][j] = orig[i][j]; 
  
  for(int a=1; a<=N ; a++){
    if(a > 1){
      REP(i, 3) REP(j, 3) if(i != j){
        int k = (9-i-j) % 3; 
        C[a][i][j] = C[a-1][i][k] + orig[i][j] + C[a-1][k][j]; 
      }
    }
    
    bool change = true; 
    while(change) REP(i, 3) REP(j, 3) if(i != j){
      change = false; 
      int k = (9-i-j) % 3; 
      if(C[a][i][j] > C[a][i][k] + C[a][k][j]) {
        C[a][i][j] = C[a][i][k] + C[a][k][j]; 
        change = true; 
      }
    }
  }
  
  for(int a=1; a <= N ; a++){
    cout << "========= " << a << " =========" << endl; 
    REP(i, 3) {REP(j, 3) cout << ((i==j) ? 0 : C[a][i][j]) << " "; cout << endl;} 
  }
  
  cout << C[N][0][2] << endl;
  
  return 0; 
}
