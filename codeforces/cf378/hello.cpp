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
#define REP1(i, to) for(int i=1; i<=to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

char W[512][512]; 
int D[512][512]; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  REP(i, 512) REP(j, 512) W[i][j]='#'; 
  REP(i, 512) REP(j, 512) D[i][j]=0; 

  int N, M, T; 
  cin >> N >> M >> T; 
  REP(i, N){
    string s;
    cin >> s;
    REP(j, M) W[i+1][j+1] = s[j]; 
  }
  
  set<PII> V[5]; 
  REP1(i, N) REP1(j, M) {
    if(W[i][j] == '#') continue; 
    
    int d=0;
    REP(k,4) d += W[i+dx[k]][j+dy[k]] == '.'; 
    V[d].insert(PII(i,j)); 
    D[i][j] = d; 
  }
  
  REP(t, T){
    int d=1;
    while(V[d].empty()) d++; 
    PII p = V[d].first();
    V[d].remove(p); 
    W[p.first][p.second] = 'X'; 
    
    REP(k, 4){
      PII pk(p.first + dx[k], p.second + dy[k]); 
      int dk = D[pk.first][pk.second]; 
      V[dk].remove(pk); 
      V[dk-1].insert(pk); 
      D[pk.first][pk.second]--; 
    }
  }
  
  REP1(i, N) {
    REP1(j, M) cout << W[i][j]; 
    cout << endl;
  }
  
  return 0; 
}
