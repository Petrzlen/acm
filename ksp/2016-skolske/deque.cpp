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
  vector<int> I(N,0);
  REP(i, N) cin >> I[i];
  vector<int> S(I.begin(), I.end()); 
  sort(S.begin(), S.end());
  map<int, int> M; 
  REP(i, N) M[S[i]] = i+1; 
  
  vector<bool> V(N+2,false); 
  int result = 0;
  
  REP(i, N) {
    int pos = M[I[i]]; 
    //cout << I[i] << " at " << pos << " <" << V[pos-1] << " >" << V[pos+1] << endl;  
    
    result += (!V[pos-1] && !V[pos+1]);
    V[pos]=true; 
  }
  
  cout << result << endl;
  
  return 0; 
}
