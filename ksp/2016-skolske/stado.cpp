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

map<LLI,LLI> rozloz(int x){
  map<LLI,LLI> result; 
  for(int i=2; i<22345678; i++){
    if(x%i==0){
      int j=0; 
      while(x%i==0){j++; x/=i;}
      result[i]=j;  
    }
  }
  if(x != 1) result[x]=1; 
  
  return result; 
}


LLI M = ((LLI)(1 << 21)) * ((LLI)(1 << 21)); 

vector<LLI> bfs(LLI from, LLI to){
  queue<LLI> todo; 
  map<LLI, LLI> B; 
  set<LLI> V; 
  
  todo.push(from); 
  B[from]=from; 
  
  map<LLI, LLI> mop = rozloz(from); 
  vector<LLI> op;
  for(map<LLI, LLI>::iterator iter = mop.begin(); iter != mop.end() ; iter++) op.push_back(iter->first); 
  
  while(!todo.empty() && todo.front() != to){
    LLI v = todo.front();
    todo.pop(); 
    
    if(V.find(v) != V.end()) continue; 
    V.insert(v); 
    
    vector<LLI> n; 
    if(v < (1<<21)) n.push_back(v*v); 
    
    REP(i, op.size()) if(v%op[i]==0) n.push_back(v/op[i]); 
    
    REP(i, n.size()) if(n[i]>0 && n[i]<M) {
      todo.push(n[i]); 
      if(B.count(n[i])==0) B[n[i]]=v; 
    }
  }
  
  //for(map<LLI, LLI>::iterator iter = B.begin(); iter != B.end(); iter++) cout << iter->second << "->" << iter->first << endl;
  
  if(B.count(to) == 0){
    cout << "PIPKOS" << endl;
    return vector<LLI>(); 
  }
  
  vector<LLI> result;
  for(; to!=B[to]; to=B[to]) {
    result.push_back(to);
  }
  result.push_back(from); 
  reverse(result.begin(), result.end()); 
  
  return result;   
}

int main(){
  LLI n, m; 
  cin >> n >> m; 
  
  map<LLI,LLI> rN = rozloz(n); 
  map<LLI,LLI> rM = rozloz(m); 
  for(map<LLI,LLI>::iterator iter=rM.begin(); iter!=rM.end(); iter++){
    if(rN.count(iter->first) == 0){
      cout << "Impossible" << endl;
      return 0; 
    }
  }
  
  vector<LLI> result = bfs(n, m); 
  REP(i, result.size()-1){
    if(i!=0) cout << " "; 
    if(result[i+1]/result[i]==result[i]) cout << 0;
    else cout << result[i]/result[i+1];  
  }
  cout << endl;

  return 0; 
}
