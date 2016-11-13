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
typedef pair<int, LLI> PII; 

int n, m; 
#define M 2048
vector<int> N[M];
vector<PII> PN; 
#define S 0
#define T 1

int C[M][M];
int R[M][M]; 

void ae(int a, int b, int c){
  if(C[a][b] != 0){
    N[a].push_back(b); 
    N[b].push_back(a); 
    
    PN.push_back(PII(a,b));
    PN.push_back(PII(b,a));
  }
  
  C[a][b] = c; 
}

int B[M]; 
bool V[M]; 
bool bfs_and_aug(int from, int to){
  //cout << "BFS======" << from << "," << to << endl;
  //REP(i, M) REP(j, M) if(R[i][j]!=0) cout << i << "," << j << ":" << R[i][j] << endl;
  REP(i, M) B[i]=-1;

  queue<int> Q;
  Q.push(from); 
  B[from]=from; 
  
  REP(i, M) V[i]=false; 
  
  while(!Q.empty() && Q.front() != to){
    int a = Q.front();
    Q.pop();
    
    if(V[a]) continue; 
    V[a]=true; 
    
    REP(i, N[a].size()){
      int b = N[a][i]; 
      if(R[a][b]>0){
        Q.push(b); 
        if(B[b]<0) B[b]=a; 
      }
    }
  }
  
  if(B[to]<0) return false; 
  
  //REP(i, M) if(B[i]>=0) cout << i << "<-" << B[i] << endl;
  
  vector<int> P; 
  int p = to; 
  do{
    P.push_back(p);
    p = B[p]; 
  }while(p != B[p]);  
  P.push_back(from); 
  
  reverse(P.begin(), P.end()); 
  
  int minr = 12345679; 
  REP(i, P.size()-1) minr = min(minr, R[P[i]][P[i+1]]); 
  
  //cout << "Augmenting path of size " << minr << endl; 
  //REP(i, P.size()) {cout << " " << P[i];}
  //cout << endl;
  
  REP(i, P.size()-1) {
    int a = P[i];
    int b = P[i+1];
    R[a][b] += (C[a][b]>0) ? -minr : minr;
    R[b][a] += (C[b][a]>0) ? -minr : minr;
  }
  
  return true; 
}

bool is_flow(int z){
  REP(i, n) C[S][2+i]=z; 
  REP(i, PN.size()) R[PN[i].first][PN[i].second]=C[PN[i].first][PN[i].second]; 
  
  while(bfs_and_aug(S,T)); 
  
  REP(i, n) if(R[S][2+i]!=0) return false;
  return true; 
}

int bs(int from, int to){
  //cout << "BS======" << from << "," << to << endl;

  if(from+1>=to) return from; 
  int m = (from+to)/2; 
  if(is_flow(m)) return bs(m, to);
  return bs(from,m); 
}

int main(){
  REP(i, M) REP(j, M) C[i][j]=0; 

  cin >> n >> m; 
  REP(i, n){
    int k;
    cin >> k;
    REP(j, k){
      int b;
      cin >> b;
      ae(2+i, n+1+b, 1); 
    }
  }
  
  REP(i, n) ae(S, 2+i, 0);
  REP(i, m) ae(n+2+i, T, 1); 
  
  if(is_flow(1)){
    cout << "YES " << bs(1,1024) << endl;
  }
  else{
    //cout << "NO==========" << endl;
    REP(i, M) REP(j, M) R[i][j] = 0;
    REP(i, M) REP(j, M) if(i>1 && j>1) R[j][i] = C[i][j];
    REP(i, m) R[T][n+2+i] = 1;
    REP(i, n) R[2+i][S] = 123456; 
  
    REP(i, M) REP(j, M) C[i][j] = R[i][j];
    
    while(bfs_and_aug(T,S)); 
    
    int result=0; 
    REP(i, m) result += 1 - R[T][n+2+i];
    cout << "NO " << result << endl; 
  }

  return 0; 
}
