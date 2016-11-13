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

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> V(N,0); 
  REP(i, N) cin >> V[i]; 
  
  int w=0; 
  int wi=-1;
  REP(i, N) if(K <= V[i] && V[i]>w){
    w=V[i];
    wi=i; 
  }
  
  if(wi==-1) REP(i, N) if(V[i] >= 2*K) wi=i; 
  
  if(wi==-1) {
    cout << -1 << endl;
    return 0;
  }
  
  V[wi] -= K; 
  
  bool all=true;
  LLI result = K+1;
  REP(i, N) {
    result += min(V[i], K-1); 
    if(V[i] >= K) all=false; 
  }
  
  if(all){
    cout << -1 << endl;
    return 0;
  }
  
  cout << result << endl;
  
  return 0; 
}
