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
  
  map<int, vector<int> > M; 
  
  REP(i, N){
    int x; 
    cin >> x; 
    
    int m = x; 
    if(m < 0) m = -m; 
    
    M[m % 10000].push_back(x); 
  }
  
  vector<PII> R; 
  
  for(map<int, vector<int> >::iterator iter = M.begin() ; iter != M.end() ; iter++){
    vector<int> V = iter->second; 
    REP(i, V.size()) REP(j, V.size()) if(i < j) R.push_back(PII(min(V[i],V[j]),max(V[i],V[j])));
  }
  
  sort(R.begin(), R.end()); 
  REP(i, R.size()) cout << R[i].first << " " << R[i].second << endl; 
  
  return 0; 
}
