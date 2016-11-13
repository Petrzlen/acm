//TODO #0

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

map<int,int> rozloz(int x){
  map<int,int> result; 
  for(int i=2; i<123456; i++){
    if(x%i==0){
      int j=0; 
      while(x%i==0){j++; x/=i;}
      result[i]=j;  
    }
  }
  return result; 
}

#define MAX 64

vector<int> bfs(int from, int to){
  queue<int> todo;
  vector<int> J(64, -1); 
  vector<bool> V(64, false);
  
  todo.push(from); 
  J[from]=from; 
  
  while(!todo.empty()){
    int v = todo.front(); 
    todo.pop(); 
    
    if(V[v]) continue;
    V[v]=true; 
    
    int N[2] = {v-1, 2*v}; 
    REP(i,2) if(0 <= N[i] && N[i] < MAX){
      todo.push(N[i]);
      if(J[N[i]]<0) J[N[i]]=v; 
    }
  }
  
  vector<int> result; 
  for(; J[to] != to; to=J[to]) result.push_back(to); 
  result.push_back(from);
  reverse(result.begin(), result.end()); 
  
  return result; 
}

int pd(vector<int>& P){
  int m=0; 
  REP(j, P.size()-1) m+=(P[j+1]/2==P[j]); 
  return m; 
}

void coutv(vector<int>& V){
  REP(i, V.size()) cout << " " << V[i];
  cout << endl;
}

void ad(vector<int>& P){
  //cout << "AD:" << endl; 
  //coutv(P); 

  if(P[P.size()-1]==1) {
    P.push_back(2); 
    P.push_back(1); 
    //coutv(P); 
    return; 
  }
  int m = max(2, *min_element(P.begin(), P.end())); 
  int mi = P.size()-1; 
  for(int i=P.size()-1; i>=0; i--) if(P[i]==m) {mi=i; break;} 
  
  vector<int> R = bfs(m-1, P[P.size()-1]); 
  P = vector<int>(P.begin(), P.begin() + mi + 1); 
  P.insert(P.end(), R.begin(), R.end()); 
  
  //coutv(P); 
}

int main(){
  int N, M; 
  cin >> N >> M; 
  map<int,int> rN = rozloz(N); 
  map<int,int> rM = rozloz(M); 
  
  vector<int> A; 
  vector<int> B; 
  vector<int> C;  
  
  for(map<int,int>::iterator iter=rM.begin(); iter!=rM.end(); iter++){
    if(rN.count(iter->first) == 0){
      cout << "Impossible" << endl;
      return 0; 
    }
  }
  for(map<int,int>::iterator iter=rN.begin(); iter!=rN.end(); iter++){
    A.push_back(iter->second); 
    B.push_back(rM[iter->first]); 
    C.push_back(iter->first); 
  }
  
  vector<vector<int> > P; 
  
  REP(i, A.size()) P.push_back(bfs(A[i], B[i])); 
  
  int maxm=0; 
  REP(i, P.size()) maxm = max(maxm, pd(P[i])); 
  
  REP(i, P.size()) while(pd(P[i])!=maxm) {
    ad(P[i]); 
  }
  REP(i, P.size()) P[i].push_back(2*P[i][P[i].size()-1]); 
  
  vector<int> result; 
  vector<int> I(P.size(), 1); 
  int m=0; 
  do{
    REP(p, P.size()){
      for(; I[p]<P[p].size() && P[p][I[p]] != 2*P[p][max(0, I[p]-1)]; I[p]++) {
        result.push_back(C[p]); 
      }
    }
    result.push_back(0); 
    REP(p, P.size()) I[p]++; 
  }while(m++<maxm); 
 
  REP(i, result.size()-1){
    if(i!=0) cout << " "; 
    cout << result[i]; 
  }
  cout << endl;
  
  return 0; 
}
