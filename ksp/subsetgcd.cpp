#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

using namespace std;

LLI gcd(LLI a, LLI b){
  if(a > b) return gcd(b, a);
  if(a == 0) return b; 
  return gcd(b%a, a);
}

int main()
{
  LLI N, D; 
  cin >> N >> D;
  
  vector<LLI> S; 
  REP(i, N){
    LLI x;
    cin >> x;
    if(x%D==0) S.push_back(x);
  }
  
  if(S.empty()){
    cout << "-1" << endl;
    return 0;
  }
  
  LLI G = S[0];
  REP(i, S.size()){
    G = gcd(G, S[i]);
  }
  if(G != D){
    cout << "-1" << endl;
  }
  else{
    cout << S.size() << endl;
    REP(i, S.size()){
      if(i!=0) cout << " ";
      cout << S[i]; 
    }
    cout << endl;
  }
  
	return 0;
}
