#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)

typedef pair<double, double> PDD;

void add(set<PDD>& S, PDD p) {
  set<PDD>::iterator iter = S.lower_bound(PDD(p.first, 0.0));
	if (iter == S.end()) {
	  iter = S.end();
		iter--;
  } 
	if (p.first <= iter->second) {
	  S.erase(iter);
		S.insert(PDD(min(iter->first, p.first), max(iter->second, p.second)))
	}
}

double solve() {
  int N;
	double P;
	cin >> N >> P;
	vector<PDD> R;
	vector<PDD> I;
	double a = 0.0, b = 0.0;
	FOR(i, N) {
	  PDD r;
		cin >> r.first >> r.second;
		R.push_back(r);
		double wh = 2.0 * (r.first + r.second);
		a += wh;
		b += wh + 2.0 * sqrt(r.first * r.first + r.second * r.second);
		I.push_back(a, b);
	}

	if (P <= a) return a;
	if (P >= b) return b;

	set<PDD> S2;
 //S2.insert(PDD(I[0].second, I[0].first));
	for (int i = 0; i < I.size(); i++) {
	  set<PDD> S1 = S2;
		add(S2, I[i])
		for (iter set<PDD>::iterator = S1.begin(); iter != S1.end(); ++iter) {
		  PDD p = *iter;
		  add(S2, PDD(p.first + I[i].first, p.second + I[i].second);
		}
	}

	return 42;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
	  printf("Case #%d: %.8f\n", t+1, solve());
  }

  return 0;
}
