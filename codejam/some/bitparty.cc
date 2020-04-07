#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)

bool can_solve(LLI R, LLI B, LLI C, const vector<LLI>& M, const vector<LLI>& S, const vector<LLI>& P, LLI val) {
	vector<LLI> T(C, 0);
	FOR(i, C) {
		T[i] = min(M[i], max(0ll, val - P[i]) / S[i]);
	}
	sort(T.begin(), T.end(), greater<LLI>());
	//cout << val << endl;
	//FOR(j, R) cout << T[j] << " ";
	//cout << endl;

	LLI s = 0;
	FOR(j, R) s += T[j];
  return s >= B;
}

LLI solve() {
  LLI R, B, C;
	cin >> R >> B >> C;
	vector<LLI> M(C, 0), S(C, 0), P(C, 0);

	FOR(i, C) {
	  cin >> M[i] >> S[i] >> P[i];
	}

  // binary search the solution
	LLI from = 1, to = 1123456789;
	while (from + 1 < to) {
	  LLI m = (from + to) / 2;
		// enough time, we can lover it
		if (can_solve(R, B, C, M, S, P, m)) {
		  to = m + 1;
		} else {
		  from = m + 1;
		}
		if (to == from + 2) {
		  return can_solve(R, B, C, M, S, P, from) ? from : from + 1;
		}
	}

	return from;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t + 1 << ": " << solve() << endl;
  }
  return 0;
}
