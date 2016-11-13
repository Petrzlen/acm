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
typedef pair<LLI, LLI> PII;
typedef pair<LLI, pair<LLI, LLI> > PI_PII; 

int main()
{
  vector<PI_PII> C;
  int N;
  LLI P=0,V=0; 
  
  cin >> N;
  REP(i, N){
    LLI v, p, m;
    cin >> v>>p>>m;
    C.push_back(PI_PII(m, PII(v,p))); 
    P+=p; 
    V+=v; 
  }
  
  sort(C.begin(), C.end());
  
  LLI B=-1; 
  LLI result = 1; 
  
  int i=0; 
  for(LLI t=1; t<123456; t++){
    V += P; 
    
    while(i < C.size() && C[i].first == t){
      LLI v = C[i].second.first; 
      LLI p = C[i].second.second; 
      LLI m = C[i].first; 
      
      V -= v + p*t; 
      P -= p; 
      i++;
    }
    
    //if(t<6) cout << V << endl;
    
    if(V>B){
      result = t; 
      B=V; 
    }
  }
  cout << result << endl;

	return 0;
}
