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
  vector<int> C(n, 0);
  REP(i, n) cin >> C[i]; 
  
  REP(i, n){
    REP(j, C[i]){
      cout << "P"; 
      cout << ((i == n-1) ? "LR" : "RL"); 
    }
    
    if(i != n-1){
      cout << "R"; 
    }
  }
  
  cout << endl;
  
  return 0; 
}
