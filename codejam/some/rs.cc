#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)
typedef pair<int, int> PII;
#define INF 1234567890

void update(int& best_l, int& best_c, int l) {
  if (l > best_l) {
	  best_l = l;
		best_c = 1;
	} else if (l == best_l) {
	  best_c++;
	}
}

void solve() {
	int S;
	cin >> S;
  vector<PII> spans;
	FOR(i, S) {
	  int D, A, B;
		cin >> D >> A >> B;
		spans.push_back(PII(D+A, D-B));
	}

  int best_l = 0;
	int best_c = 0;
	FOR(i, S) {
	  PII p1(spans[i].first, INF);
		PII p2(INF, spans[i].second);

		bool b1 = false;
		bool b2 = false;
	  for (int j = i + 1; j < S; j++) {
		  int a = spans[j].first;
			int b = spans[j].second;
			bool u = false;
		  if (a != p1.first) {
			  if (p1.second == INF) {
				  p1.second = b;
				} else if (p1.second != b) {
				  if (!b1) {
						update(best_l, best_c, (j - i));
						u = true;
					}
					b1 = true;
				}
			}

			if (b != p2.second) {
			  if (p2.first == INF) {
				  p2.first = a;
				} else if (p2.first != a) {
				  if (!b2) {
					  if (!u) update(best_l, best_c, (j - i));
					  b2 = true;
					}
				}
			}
		}

		if (!b1 || !b2) {
		  update(best_l, best_c, S - i);
		}
	}

	cout << best_l << " " << best_c << endl;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t + 1 << ": ";
		solve();
  }
  return 0;
}
