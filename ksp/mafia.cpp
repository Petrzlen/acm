#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

LLI mod = 1000000007; 

int main()
{
  int n, q, t; 
  cin >> n >> q >> t;
  
  vector<LLI> P(t+1,0); 
  P[t]=1; 
  
  vector<int> J(n,-1); 
  vector<bool> V(n, false); 
  vector<int> A(n, 0); 
  
  REP(i, n){
    cin >> A[i]; 
  }
  
  REP(i, q){
    int b,c;
    cin >> b >> c;
    J[c-1]=b-1;
  }
  
  bool bad=false;
  
  REP(j, n){
    if(V[j]) continue; 
    
    vector<int> C;
    for(int i=j; i != -1; i = J[i]) {
      if(V[i]) {
        bad = true; 
        break;
      }
      C.push_back(A[i]); 
      V[i]=true; 
    }
    
    if(bad){
      break; 
    }
    
    vector<int> S(C.size()+1, 0); 
    for(int i=C.size()-1; i>=0; i--) S[i] = S[i+1] + C[i]; 

    //REP(i, C.size()) cout << C[i] << " " << S[i] << endl;
    
    
    REP(c, C.size()){
      vector<bool> Qnext(t+1, false);
      vector<int> Pnext(t+1, 0);
      
      int s = S[c]; 
      for(int i=t; i>=s; i--){
        if(P[i]>0 || Pnext[i]>0){
          Pnext[i-s] = (Pnext[i]+P[i]) % mod; 
          Qnext[i-s] = true; 
        }
      }
      if(C.size() > 1 && c > 0){
        REP(i, t+1) {
          Pnext[i]=(Qnext[i])?Pnext[i]:0;
        }
      }
      REP(i, P.size()) P[i] = (Pnext[i] + P[i]*(c==0)) % mod;
      
      //REP(i, P.size()) cout << c << " P["<<P.size()-1-i<<"]=" << P[P.size()-1-i] << endl;
    }
  }
  
  cout << (bad ? 0 : P[0]) << endl;
  
	return 0;
}
