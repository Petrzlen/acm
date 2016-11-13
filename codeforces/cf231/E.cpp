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
#define INF 1234567890

typedef long long int LLI;
typedef pair<int, int> PII; 

int N, M;
vector<PII> G[31234]; 
vector<int> R;
vector<int> NWR[10];
vector<int> D[11]; 
vector<int> mD(31234, INF); 

vector<bool> V(N, false);
void s(int r){ 
  REP(i, V.size()) V[i] = false; 

  priority_queue<PII, vector<PII>, greater<PII> > Q; 
  REP(i, NWR[r].size()) {
    D[r][NWR[r][i]]=0; 
    Q.push(PII(0, NWR[r][i])); 
  }
  
  while(!Q.empty()){
    PII p = Q.top(); 
    Q.pop(); 
    
    int id = p.second; 
    if(V[id]) continue; 
    V[id] = true; 
    
    int d = p.first; 
    D[r][id] = d; 
    
    REP(i, G[id].size()) Q.push(PII(d + G[id][i].second, G[id][i].first)); 
  }
}

int result = 0; 

void c(int n){

  vector<int> C; 

  priority_queue<PII, vector<PII>, greater<PII> > Q; 
  Q.push(PII(0, n)); 
  
  while(!Q.empty()){
    PII p = Q.top(); 
    Q.pop(); 
    
    int id = p.second; 
    if(V[id]) continue; 
    V[id] = true; 
    
    int d = p.first; 
    if(mD[id] <= d) continue; 
    
    C.push_back(id); 
    
    REP(i, G[id].size()) Q.push(PII(d + G[id][i].second, G[id][i].first)); 
  }
  
  result += C.size(); 
  REP(i, C.size()) V[C[i]] = false; 
}

int main(){ 
  cin >> N >> M;
  
  R = vector<int>(N, 0); 
  REP(i, N) {
    cin >> R[i];
    R[i]--; 
    NWR[R[i]].push_back(i); 
  }
 
  REP(i, M){
    int a, b, v; 
    cin >> a >> b >> v;
    G[a].push_back(PII(b, v)); 
    G[b].push_back(PII(a, v)); 
  }
  
  REP(i, 11) D[i] = vector<int>(N,INF); 
  
  for(int i=9; i>=0; i--) s(i);  
  REP(i, V.size()) V[i] = false; 
  for(int i=9; i>=0; i--) {
    REP(j, N) mD[j] = min(mD[j], D[i+1][j]); 
    REP(j, NWR[i].size()) c(NWR[i][j]); 
  }
  
  cout << result << endl;
  
  return 0; 
}
