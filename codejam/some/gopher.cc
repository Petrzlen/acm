#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef long long int LLI;
typedef pair<int, int> PII;

#define FOR(i, to) for(int i = 0; i < to; i++)

void solve();

int main() {
  int T;
	cin >> T;
	FOR(t, T) solve();
	return 0;
}

void solve() {
  int A;
	cin >> A;
	// cerr << "test case " << A << endl;

	int R, C;
	if (A == 20) {R = 5; C=4;}
	else {R = 10; C = 20;}

  int sR = 2, sC = 2;
	set<PII> todo;
	FOR(r, R) FOR(c, C) todo.insert(PII(sR + r, sC + c));

	while(!todo.empty()) {
	  PII m = *(todo.begin());
		// to cover left top, enough to do one to right and to down
		m.first++;
		m.second++;
		// make sure in the allocated rectangle boundary
		m.first = max(sR + 1, min(sR + R - 2, m.first));
		m.second = max(sC + 1, min(sC + C - 2, m.second));
		cout << m.first << " " << m.second << endl;
		cout.flush();
		// cerr << "go " << m.first << " " << m.second << endl;
		// update todo list
		int r, c;
		cin >> r >> c;
		if (r <= 0 || c <= 0) break;
		todo.erase(PII(r,c));
		// cerr << "er " << r << " " << c << " s: " << todo.size() << endl;
	}
}
