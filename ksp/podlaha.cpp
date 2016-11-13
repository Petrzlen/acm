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

typedef unsigned long long int LLI;
typedef pair<int, int> PII; 

int main(){
  LLI a,b,c,d; 
  cin >> a >> b >> c >> d; 
  
  LLI s = min(a,b) + min(c,d);
  if(s == 0){
    cout << 0 << endl;
    return 0; 
  }
  
  LLI result = 1; 
  while(result <= (s / result)){ // overflow 
    result += 10000;
  }
  result -= 10000; 
  while(result <= (s / result)){ // overflow 
    result += 1;
  }
  result -= 1; 
  
  cout << result << endl;
  
  return 0; 
}
