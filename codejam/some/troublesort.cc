#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define FOR(i, to) for(int i = 0; i < to; i++)

int solve() {
  int N;
	cin >> N;
	vector<int> V(N, 0);
	vector<int> S[2];
	FOR(i, N) {
		cin >> V[i];
		S[i % 2].push_back(V[i]);
	}
	sort(V.begin(), V.end());
	FOR(i, 2) sort(S[i].begin(), S[i].end());
	FOR(i, N) if(S[i%2][i/2] > V[i]) return i;
	return -1;
}

int solve2() {
  int N;
	cin >> N;
	vector<int> V(N, 0), C(N, 0);
	FOR(i, N) cin >> V[i];
	FOR(i, N) C[i] = V[i];
	sort(C.begin(), C.end());
	bool done = false;
	while (!done) {
	  done = true;
		FOR(i, N-2) {
		  if (V[i] > V[i+2]) {
			  done = false;
				swap(V[i], V[i+2]);
			}
		}
	}
	FOR(i, N) if(V[i] > C[i]) return i;
	return -1;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t+1 << ": "; 
		int r = solve();
		if (r < 0) cout << "OK";
		else cout << r;
		cout << endl;
  }
  return 0;
}
