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
  cin >> N >> M;
  vector<string> S(N, ""); 
  REP(i, N) cin >> S[i]; 
  int invalid=0; 
  
  vector<int> C(N,0); 
  REP(m, M){
    string s; 
    cin >> s;
    
    int p=0; 
    int c=0;
    REP(i, s.size()) if(s[i]=='X'){
      p=i;
      c++; 
    }
    if(c==1) C[p]++; 
    else invalid++; 
  }
  
  vector<PII> V; 
  REP(i, C.size()) V.push_back(PII(-C[i], i)); 
  sort(V.begin(), V.end());
  
  REP(i, V.size()) printf("%s %.2f%%\n", S[V[i].second].c_str(), abs(100.0 * (-(double)V[i].first)/(double)M)); 
  printf("Invalid %.2f%%\n", 100.0 * (double)invalid/(double)M); 

  return 0; 
}
