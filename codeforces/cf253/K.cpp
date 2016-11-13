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
  
  vector<int> T(N, 0);
  REP(i, N) cin >> T[i];
  
  vector<PII> R; 
  int d = 0; 
  
  while(d<N){
    int dup=d; 
    while(dup<N && T[dup]>=dup-d+1) dup++; 
    
    int ddown=d; 
    int dval=T[d];
    while(ddown<N && dval>=1){
      dval = min(dval, T[ddown]) - 1; 
      ddown++;
    }
    
    //cout << d << " down:" << ddown << " up:" << dup << endl;
    
    if(ddown > dup) R.push_back(PII(ddown-1, d));
    else R.push_back(PII(d, dup-1));
    d = max(dup, ddown); 
  }
  
  cout << R.size() << endl;
  REP(i, R.size()) cout << R[i].first+1 << " " << R[i].second+1 << endl;
  
  
  return 0; 
}
