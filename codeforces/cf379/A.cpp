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
  LLI z=0; 
  cin >> a >> b; 
  
  LLI result = 0; 
  while(a > 0){
    result += a; 
    z += a; 
    a = z / b;
    z = z % b; 
  }
  
  cout << result << endl;
  
  return 0; 
}
