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
  LLI N;
  cin >> N; 
  
  vector<LLI> V(N-1,0); 
  REP(i, N-1) cin >> V[i]; 
  
  LLI sum = 0;
  REP(i, N-1) sum += V[i]; 
  
  set<LLI> S; 
  REP(i, N-1) S.insert(V[i]);
   
  vector<LLI> result; 
   
  REP(i, N-1) {
    LLI t = V[i]*N - sum; 
    if(S.find(t) == S.end()) result.push_back(t);
  }
  
  if(sum % (N-1) == 0){
    LLI pipkos = sum / (N-1); 
    if(S.find(pipkos) == S.end()) result.push_back(pipkos); 
  }
  
  sort(result.begin(), result.end());
  
  REP(i, result.size()) cout << result[i] << endl;
  
  return 0; 
}
