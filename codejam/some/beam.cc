#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long int LLI;
#define FOR(i, to) for(int i = 0; i < to; i++)

LLI damage(const string& str) {
	LLI r = 0;
	LLI s = 1;
	FOR(i, str.size()) {
		if(str[i] == 'S') r += s;
		if(str[i] == 'C') s *= 2;
	}
	return r;
}

bool reduce(string& s) {
  // cout << "reduce " << s << " " << damage(s) << endl;
  int last = -1;
	FOR(i, s.size() - 1) {
	  if (s[i] == 'C' && s[i+1] == 'S') {
		  last = i;
		}
	}
	// cout << last << endl;
	if (last < 0) return false;
	swap(s[last], s[last+1]);
	return true;
}

LLI solve() {
  LLI D;
	string S;
	cin >> D >> S;
	FOR(r, 10000) {
	  if (damage(S) <= D) return r;
		if (!reduce(S)) return -1;
	}
	return -1;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
	  int r = solve();
		cout << "Case #" << t + 1 << ": ";
		if(r < 0) cout << "IMPOSSIBLE";
		else cout << r;
		cout << endl;
  }
  return 0;
}
