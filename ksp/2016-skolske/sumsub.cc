#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long int LLI;
#define MOD 1000000007

#define REP(i, to) for (int i = 0; i < to; ++i)

int main() {
  LLI N;
  cin >> N;
  
  LLI powN = 1;  // N >= 2
  LLI res = 0;
  REP(i, N-1) powN = (powN * 2) % MOD;
  powN = (powN + MOD - 1) % MOD;  // proper subset
  REP(i, N) {LLI x; cin >> x; res = (res + (powN * x)) % MOD;}
  cout << res << endl;

  return 0;
}
