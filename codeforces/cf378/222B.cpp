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
  vector<int> A(N, 0); 
  vector<int> B(N, 0); 
  vector<int> S; 
  
  REP(i, N){
    cin >> A[i] >> B[i];
    S.push_back(A[i]); 
    S.push_back(B[i]); 
  }
  
  sort(S.begin(), S.end()); 
  int mi = N/2 - 1;
  int m = S[N-1]; 
  
  REP(i, A.size()) cout << (i <= mi || A[i] <= m); 
  cout << endl;
  REP(i, B.size()) cout << (i <= mi || B[i] <= m); 
  cout << endl;
  
    
  return 0; 
}
