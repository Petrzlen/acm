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
typedef pair<LLI, LLI> PII; 

int main(){
  int N, M;
  cin >> N >> M; 
  
  vector<LLI> H(N, 0);
  REP(i, N) cin >> H[i]; 
  
  vector<vector<PII> > G(N, vector<PII>()); 
  REP(i, M) {
    int a, x, y; 
    cin >> a >> x >> y; 
    G[a-1].push_back(PII(x-1,y-1)); 
  }
  
  vector<PII> HS(N, 0); 
  REP(i, N) HS(PII(H[i], i)); 
  sort(HS.begin(), HS.end()); 
  
  vector<bool> D(N, -1); 
  D[HS[0].second] = H[HS[0].second];
  
  return 0; 
}
