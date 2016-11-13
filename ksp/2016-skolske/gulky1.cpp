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
  int n; 
  cin >> n; 
  vector<LLI> P(n+1, 0); 
  LLI s = 0;
  
  REP(i, n+1) cin >> P[i]; 
  for(int i=n; i>0; i--){
    P[i] += s; 
    if(P[i]%i != 0) {cout << "Nie" << endl; return 0;} 
    s += P[i] / i; 
    P[i] = 0;  
  }
  cout << "Ano" << endl;
   
  return 0; 
}
