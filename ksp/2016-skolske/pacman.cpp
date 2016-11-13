#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP1(i, to) for(int i=1; i<=to; i++)
typedef long long int LLI;

int N, T;
vector<int> V[512345];
int D[512345];

vector<int> R; 
int visitsum=0; 

int dfs(int from, int act){
  if(V[act].size() == 1){
    D[act]=0;
  }
  else{
    int m = 123456789;
    for(int i=0; i<V[act].size(); i++){
      if(V[act][i] == from) continue; 
      m = min(m, dfs(act, V[act][i])); 
    }
    D[act] = m+1; 
  }
  return D[act];
}

void longest(int v, vector<int>& out){
  out.push_back(v);
  
  if(V[v].size()==1) return; 
  
  int nid=V[v][0]; 
  for(int i=0; i<V[v].size(); i++) if(D[V[v][i]] + 1 == D[v]) nid = V[v][i];
  for(int i=0; i<V[v].size(); i++) if(v != V[v][i] && D[V[v][i]] == D[v]) nid = V[v][i];
  
  D[v] = -1;
  longest(nid, out);  
}

bool branch(int from, int notto, int act, int& over){
  if(T+1 <= R.size()) return false;
  if(over == 0 && notto == -1) return false;
  if(notto==-1) over--;
  
  R.push_back(act); 
  visitsum++; 
  
  if(V[act].size()==1) return true;

  for(int i=0; i<V[act].size(); i++){
    if(V[act][i] == from || V[act][i] == notto) continue; 
    
    if(branch(act, -1, V[act][i], over)){
      R.push_back(act); 
    }
    else{
      break;
    }
  }
}

int main()
{
  cin >> N >> T;
  REP1(i, N-1){
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int l = 0;
  REP1(i, N) if(V[i].size()!=1) l = i;
  REP1(i, N) D[i]=0; 
  dfs(0, l); 
  
  //REP1(i, N) cout << i << " " << D[i] << endl;
  int mid=1;
  REP1(i,N) if(D[mid] < D[i]) mid = i;
  
  vector<int> l1, l2; 
  int mval = D[mid];
  longest(mid, l1); 
  D[mid] = mval; 
  longest(mid, l2); 
  
  vector<int> route;
  for(int i=l1.size()-1; i>=0; i--) route.push_back(l1[i]);
  for(int i=1; i<l2.size(); i++) route.push_back(l2[i]);
    
  //REP1(i, route.size()) cout << route[i-1] << endl;
    
  int over = (T-route.size()+1)/2;
  visitsum++;
  
  R.push_back(route[0]); 
  REP1(i, route.size()-1){
    branch(route[i-1], ((i+1)>=route.size())?-2:route[i+1], route[i], over);
  }
  
  cout << visitsum << endl;
  cout << R.size() - 1 << endl;
  for(int i=0; i<R.size(); i++){
    if(i != 0) cout << " ";
    cout << R[i];
  }
  cout << endl;
   
	return 0;
}
