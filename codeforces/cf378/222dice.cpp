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
  int a, b;
  cin >> a >> b;
  
  int w=0, d=0; 
  for(int i=1; i<7; i++){
    if(abs(a-i) < abs(b-i)) w++; 
    if(abs(a-i) == abs(b-i)) d++; 
  }
  
  cout << w << " " << d << " " << 6 - w - d << endl; 
  
  return 0; 
}
