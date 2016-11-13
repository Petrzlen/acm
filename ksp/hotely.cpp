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

int N; 
vector<vector<int> > G; 

vector<LLI> bfs(int s, int vis){
    vector<LLI> P; 
    vector<bool> V(N, false); 
    if(vis >= 0) V[vis] = true; 
    
    queue<PII> Q; 
    Q.push(PII(s, 0)); 
    
    while(!Q.empty()){
      int v = Q.front().first; 
      int d = Q.front().second; 
      Q.pop(); 
      
      if(V[v]) continue; 
      V[v] = true; 
      
      //cout << "  v=" << v << "  d=" << d << endl;
    
      REP(j, G[v].size()) Q.push(PII(G[v][j], d+1)); 

      if(P.size() <= d) P.resize(d+1); 
      P[d]++; 
    }
    
    return P; 
}

int main(){
  cin >> N;
  
  G = vector<vector<int> >(N, vector<int>()); 
  REP(i, N-1){
    int a,b;
    cin >> a >> b;
    G[a-1].push_back(b-1); 
    G[b-1].push_back(a-1); 
  }
  
  //REP(i, G.size()) REP(j, G[i].size()) cout << "  " << i << "<->" << G[i][j] << endl;
  
  LLI result = 0; 
  REP(i, N){
    if(G[i].size() <= 1) continue; 
    
    vector<LLI> P = bfs(i, -1); 
    vector<vector<LLI> > B;
    REP(j, G[i].size()) B.push_back(bfs(G[i][j], i)); 
    
    //cout << "==i=" << i << " n=" << G[i].size() << endl;
    //REP(p, P.size()) cout << "  " << p << ": " << P[p] << endl;
    
    REP(p, P.size()) if(p>0) {
      vector<LLI> D; 
      REP(b, B.size()) if(B[b].size() >= p) D.push_back(B[b][p-1]); 
      if(D.size()<3) continue; 
      
      LLI s1=0, s2=0, s3=0; 
      REP(d, D.size()) {
        s1 += D[d]; 
        s2 += D[d]*D[d]; 
        s3 += D[d]*D[d]*D[d]; 
      }
      
      LLI add=s1*s1*s1 - s3; 
      REP(d, D.size()){
        add -= 3 * D[d] * (s2 - D[d]*D[d]);
      }
      add /= 6; 
      
      //cout << "i=" << i << endl;
      //REP(d,D.size()) cout << "  " << d << ": " << D[d] << endl;
      //cout << "add=" << add << endl;
      
      result += add; 
    }
  }
  
  cout << result << endl; 
  
  return 0; 
}
