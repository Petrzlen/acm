#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
typedef long long int LLI;
#define MOD 1000000007
#define BASE 31
#define MIN 32
#define MAX 126
#define YOLO 5

#define REP(i, to) for (int i = 0; i < to; ++i)
#define YOLO_FOR(i) for (int i = -YOLO; i <= YOLO; ++i)

LLI solve(int Ci, int d1, vector<int>& C, vector<map<int, LLI> >& res) {
  if (Ci >= C.size()) return 0;
  int v1 = C[Ci] + d1 * BASE;
  if (res[Ci].count(v1)) return res[Ci][v1];

  LLI r = 0;
  YOLO_FOR(d2) {
    int v2 = v1 + d2;
    if (v2 < MIN || MAX < v2) continue;
    r = (r + solve(Ci + 1, -d2, C, res)) % MOD;
  }
  res[Ci][v1] = r;
//  cout << Ci << "\t" << d1 << "\t" << v1 << "\t" << r << endl;
  return r;
}

int main() {
  string S;
  // low endian
  getline(cin, S);
  vector<int> C(S.size()+YOLO);
  REP(i, S.size()) C[i+YOLO] = S[i];
//  for (int j = C.size() - 1; j > 0; j--) if (C[j] >= BASE) {
//    C[j-1] += C[j] / BASE;
//    C[j] %= BASE;
//  }
  // REP(i, C.size()) cout << C[i] << endl;
  vector<map<int, LLI> > res(C.size());
  YOLO_FOR(i) {
    int j = C[C.size() - 1] + i * BASE;
    res[C.size() - 1][j] = (j >= MIN && j <= MAX);
  }
 
  cout << solve(YOLO, 0, C, res) << endl; 

  return 0;
}
