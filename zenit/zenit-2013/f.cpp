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
  LLI a, b, x;
  cin >> a >> b >> x;
  LLI origa = a; 
  
  if(b==0) a=1; 
  for(; b>1 && a<x && a>0 ; b--, a*=origa); 
  
  if(a==x) cout << "rovne" << endl;
  if(a<x) cout << "menej" << endl;
  if(a>x) cout << "viac" << endl;
  
  return 0; 
}
