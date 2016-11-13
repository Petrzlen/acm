#include <iostream>
#include <vector>
#include <cstdio> 
#include <stack> 

using namespace std; 

#define REP(i, to) for(int i=0; i<to; i++)

typedef struct{
  int from;
  int to;
  int cap;
  int used; 
}EDGE; 

vector<EDGE> E; 
vector<int> V[512];
//0-(N-1) - KSPaci, N-(N-D-1) jedla

void add(int from, int to, int cap){
  EDGE e;
  e.from = from;
  e.to = to;
  e.cap = cap;
  e.used = 0; 
  V[from].push_back(E.size());
  V[to].push_back(E.size());
  E.push_back(e); 
}

//+1 flow
bool augmenting_path(int S, int T)
{
  int B[T+1]; 
  REP(i, T+1) B[i]=-1;
  
  stack<int> N;
  N.push(S); 
  B[S]=-2; 
  
  while(!N.empty()){
    int v = N.top();
    if(v==T) break;
    N.pop();
    
    REP(i, V[v].size()){
      EDGE e = E[V[v][i]]; 
      if(v == e.from && (B[e.to] != -1 || e.cap == e.used)) continue; 
      if(v == e.to && (B[e.from] != -1 || e.used == 0)) continue; 
      
      int n = (v == e.from) ? e.to : e.from; 
      B[n]=V[v][i];
      N.push(n); 
    }
  }
  
  if(N.empty()) return false;
  
  int b = T;
  //cout << "Path: " << endl; 
  while(B[b] != -2){
    EDGE e = E[B[b]]; 
    E[B[b]].used += (e.to == b) ? 1 : -1; 
    b = (e.to == b) ? e.from : e.to; 
    //cout << b << endl;
  }
  return true; 
}

int main()
{
  int N, K, D;
  cin >> N >> K >> D; 
  
  int S = N+D; //source
  int T = N+D+1; //sink
  
  REP(i, D){
    int x;
    cin >> x;
    add(N+i, T, x); 
  }
  REP(n, N){
    int x; 
    cin >> x;
    REP(i, x){
      int y;
      cin >> y;
      add(n, N+y-1, 1);
    }
  }
  REP(i, N){
    add(S, i, K);
  }
  
  /*
  REP(i, T) {
    REP(j, V[i].size()) {
      EDGE e = E[V[i][j]];
      cout << e.from << "->" << e.to << ":("<< e.cap << "," << e.used << ") ";
    } 
    cout << endl;
  }*/
  while(augmenting_path(S, T)); 
  
  int result = 0;
  REP(i, V[T].size()) result += E[V[T][i]].used;
  cout << result << endl;  
    
	return 0;
}
