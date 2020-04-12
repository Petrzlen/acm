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
#include <unordered_map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define LOG 0

typedef long long int LLI;
typedef pair<int, int> PII; 

int main() {
  int K, N, T;
  scanf("%d%d%d", &K, &N, &T);

  // Vacant seats
  set<PII> S[K];
  REP(s, K) S[s].insert(PII(N-1,0));

  REP(i, T) {
    int pl, st, fn;
    scanf("%d%d%d", &pl, &st, &fn);
    pl--; st--; fn--;
    if (LOG) cout << pl << " " << st << " " << fn << endl;

    const auto& iter = S[pl].lower_bound(PII(fn, -1));
    if (iter == S[pl].end()) cout << "SHIT no vacancy" << endl;

    PII p = *iter;
    S[pl].erase(iter);
    if (LOG) cout << "lb: " << p.first << " " << p.second << endl;
    if (p.first > fn) {
      PII n(p.first, fn);
      if (LOG) cout << "i1: " << n.first << " " << n.second << endl;
      S[pl].insert(n);
    }
    if (p.second < st) {
      PII n(st, p.second);
      if (LOG) cout << "i2: " << n.first << " " << n.second << endl;
      S[pl].insert(n);
    }
  }
  vector<int> D1(N,-1);
  REP(s, K) for (const PII& p : S[s]) {
    D1[p.second] = max(D1[p.second], p.first);
    if (LOG) cout << "va " << p.first << " " << p.second << endl;
  }
  for (int i=1; i < N; ++i) D1[i] = max(D1[i], D1[i-1]);
  vector<int> D2 = D1;
  for (int i=N-1; i>=0; --i) {
    if (LOG) cout << "d1 " << i << " " << D1[i] << endl;
    D2[i]=max(D2[D1[i]],D1[i]);
  }

  LLI res = 0;
  REP(i, N) res += D2[i] - D1[i];
  cout << res << endl;

  return 0;
}
