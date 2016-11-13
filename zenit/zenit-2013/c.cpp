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
  int N;
  cin >> N; 
  vector<int> V(N,0); 
  REP(i, N) cin >> V[i]; 
  
  sort(V.begin(), V.end()); 
  cout << V[V.size()-6] << endl;
  
  return 0; 
}
