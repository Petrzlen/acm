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
  
  int C=0;
  int J=0; 
  
  vector<int> mids; 
  REP(i, N){ 
    int M;
    cin >> M;
    vector<int> S(M, 0); 
    REP(j, M) cin >> S[j]; 
    REP(j, M/2) {
      C += S[j];
      J += S[M-1-j]; 
    }
    if(M%2==1) mids.push_back(S[M/2]); 
  }
  
  sort(mids.begin(), mids.end(), greater<int>()); 
  REP(i, mids.size()) {
    if(i%2==0) C += mids[i]; 
    else J += mids[i]; 
  }
  
  cout << C << " " << J << endl;
  
  return 0; 
}
