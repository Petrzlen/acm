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
  
  vector<int> I(N, 0);
  REP(i, N) cin >> I[i]; 
  
  vector<LLI> L(N+1, 0); 
  REP(i, N) L[i+1] = L[i] + (I[i] == 1); 
  
  LLI result = 0; 
  REP(i, N) if(I[i] == 0) result += L[i]; 
  
  cout << result << endl; 
  
  return 0; 
}
