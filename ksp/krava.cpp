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
  LLI a, b;
  cin >> a >> b; 
  
  LLI r = 0; 
  
  for(LLI t=0; t<=a+b; t=2*t+1){
    LLI ab = min(t,a); 
    LLI bb = min(t,b); 
  
    LLI d = min(t+1, max(ab+bb-t+1,0LL)); 
    r += d; 
    //cout << "t=" << t << " d=" << d << " r=" << r << endl;
  }
  
  cout << r << endl;
   
  return 0; 
}
