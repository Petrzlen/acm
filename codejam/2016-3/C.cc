#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)
#define MOD 1000000007
typedef long long int LLI;
typedef pair<LLI,LLI> PII;

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ":";
    int D,N,F,E;
    cin >> D >> N >> F >> E;
    int M = (D==2) ? N : 1;
//  cout << D << " " <<  N << " "<< F << " "  << E << " " << M;

    LLI m[M+1][N+1];
    REP(i, M+1) REP(j, N+1) m[i][j]=0;
    m[1][1]=1;
    set<PII> S;
    REP(i, F) {
        int x=1,y=1;
        if (D==2) cin >> x >> y;
        if (D==1) cin >> y;
        S.insert(PII(x,y));
        m[x][y]=0;
    }
    REP(i, M+1) { REP(j, N+1) {
      if (i==0||j==0) continue;
      if (i==1 && j==1 && m[1][1]==1) continue;
      if(S.find(PII(i,j)) != S.end()) continue;
      m[i][j]=(m[i-1][j]+m[i][j-1]) % MOD;
//      cout << m[i][j] << " ";
    }} // cout << endl; }
    REP(i, E) {
      int x=1,y=1;
      if (D==2) cin >> x >> y;
      if (D==1) cin >> y;
      cout << " " << m[x][y];
    }
    cout << endl;
  }
  return 0;
}
