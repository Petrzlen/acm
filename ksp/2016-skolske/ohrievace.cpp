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
  int N, M; 
  cin >> N;
  vector<int> B(N, 0); 
  REP(i, N) cin >> B[i]; 
  
  cin >> M; 
  vector<PII> S(M, PII(0,0)); 
  REP(i, M) cin >> S[i].second >> S[i].first; 
  
  sort(S.begin(), S.end()); 
  vector<PII> A;
  int bq = -1; 
  REP(i, S.size()) if(S[i].second > bq){
    A.push_back(PII(S[i].second, S[i].first));
    bq = S[i].second; 
  }
  
  LLI result = 0; 
  REP(i, B.size()) result += lower_bound(A.begin(), A.end(), PII(B[i], 0))->second; 
  cout << result << endl;
  
  return 0; 
}
