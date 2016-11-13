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

int m(char c){
  if(c=='<') return 0;
  if(c=='>') return 1; 
}

int main(){
  int N;
  cin >> N;
  
  string S;
  cin >> S; 
  
  vector<bool> J(S.size(), false); 
  vector<int> L(2, -1); 
  char lc='=';
  
  REP(i, S.size()){
    if(S[i] == '=') continue; 
  
    char c = S[i];
    int cm = m(S[i]);  
    if(lc != c) {
      if(L[(cm+1)%2]>0) J[L[(cm+1)%2]] = true; 
    }
    
    L[cm] = i; 
    lc = c; 
  }
  
  //REP(i, J.size()) cout << i << ":" << J[i] << endl;
  
  vector<int> V(S.size() + 1, 0); 
  int mi = 0;
  int ma = 0; 
  
  REP(i, S.size()){
    if(S[i]=='=') V[i+1]=V[i]; 
    if(S[i]=='<') {
      if(J[i]) V[i+1]=max(ma, V[i]+1); 
      else V[i+1]=V[i]+1; 
    }
    if(S[i]=='>') {
      if(J[i]) V[i+1]=min(mi, V[i]-1); 
      else V[i+1]=V[i]-1;
    }
    mi = min(mi, V[i+1]); 
    ma = max(ma, V[i+1]); 
  }
  
  if(ma - mi >= N) {
    cout << -1 << endl;
    return 0;
  }
  
  REP(i, V.size()) cout << (char)('a' - mi + V[i]);
  cout << endl;
  
  return 0; 
}
