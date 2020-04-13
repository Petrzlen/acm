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

void rem(vector<vector<int>>& G, vector<bool>& L, vector<int>& NL, int y) {
  // cout << "rem " << y << " L:" << L[y] << " NL: " << NL[y] << endl;
  if (L[y]) return;
  L[y]=true;
  REP(i, G[y].size()) {
    int n = G[y][i];
    NL[n]++;
    if(NL[n] * 2 >= G[n].size()) rem(G, L, NL, n);
  }
}

int main(){
  int N, D, X, Y;
  cin >> N >> D >> X >> Y;
  vector<vector<int>> G(N+1, vector<int>());
  REP(d, D) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> L(N+1, 0);
  vector<int> NL(N+1, 0);
  rem(G,L,NL, Y);
  cout << ((L[X])?"leave":"stay") << endl;
  return 0; 
}
