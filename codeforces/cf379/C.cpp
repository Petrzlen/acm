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
  vector<PII> V(n, PII(0,0)); 
  REP(i, n) {cin >> V[i].first; V[i].second = i;} 
  sort(V.begin(), V.end()); 
  
  vector<int> R(n, 0); 
  
  int m = -1;
  REP(i, n) {
    V[i].first = max(m+1, V[i].first); 
    m = V[i].first;
    R[V[i].second] = V[i].first; 
  }
  
  REP(i, n) {
    if(i != 0) cout << " ";
    cout << R[i];
  }
  cout << endl;
  
  return 0; 
}
