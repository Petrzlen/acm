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
  LLI N, D, A, B;
  cin >> N >> D >> A >> B; 
  
  LLI s = 0; 
  LLI l = 0;
  cin >> l; 
  
  LLI kx = 1;
  LLI ky = 1; 
  
  REP(i, N-1){
    LLI p;
    cin >> p; 
    
    if(p>l){
      ky = 1; 
      LLI b = min(kx*A*p, D);
      b /= p; 
      
      s += b; 
      D -= b*p;
      kx++; 
    }
    if(p<l){
      kx = 1; 
      LLI b = min(s, ky*B);
      
      s -= b; 
      D += b*p;
      ky++; 
    }
    if(p==l){
      kx=1;
      ky=1; 
    }
    
    l=p; 
    
    //cout << "round " << i+2 << ":" <<  D << " " << s << endl;
  }
  
  cout << D << " " << s << endl;
  
  return 0; 
}
