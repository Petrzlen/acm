#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

int main()
{
  LLI s; 
  bool result=false;
  cin >> s; 
  
  if(s % 2 == 0){
    s /= 2; 
    map<LLI, LLI> Q;
    for(LLI i=0; i*i <= s; i++) {
      Q[i*i] = i; 
    }
     
     
    for(LLI i=0; i*i <= s; i++){
      if(Q.count(s - i*i) == 0) continue; 
      LLI j = Q[s-i*i];
        
      LLI d = 10000000; 
      cout << d << " " << d << endl;
      cout << d+2*i << " " << d+2*j << endl;
      cout << d+j << " " << d-i << endl;
      cout << d+2*i+j << " " << d-i+2*j << endl;
        
      result=true;
      break;
    }
  }
  
  if(!result) REP(i, 4) cout << "0 0" << endl; 
  
	return 0;
}
