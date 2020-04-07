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
#define INF 1234567890
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve() {
  int S;
	cin >> S;

  int best_l = 0;
	int best_c = 0;
  map<PII, int> runs;
	FOR(i, S+1) {
	  int m = INF + 1, n = INF + 1; // hack
	  if (i != S) {
	    int D, A, B;
		  cin >> D >> A >> B;
		  m = D + A;
		  n = D - B;
		}
		
		map<PII, int> new_runs;
		set<int> starts_counted; // lazyness
		for (map<PII, int>::iterator iter = runs.begin(); iter != runs.end(); iter++) {
		  PII mn = iter->first;
			if ((i != S) && (mn.first == m || mn.second == n)) {
			  new_runs[mn] = iter->second;
				continue;
			}
			if (i != S && mn.first == INF) {
			  new_runs[PII(m, mn.second)] = iter->second;
				continue;
			}
			if (i != S && mn.second == INF) {
			  new_runs[PII(mn.first, n)] = iter->second;
				continue;
			}
			// this run cannot be continued, account it
			int l = i - iter->second;
			if (starts_counted.find(iter->second) != starts_counted.end()) continue;
			if (l > best_l) {
			  starts_counted.insert(iter->second);
			  best_l = l;
				best_c = 1;
				// cout << "best_l " << best_l << " best_c " << best_c << endl;
			} else if (l == best_l) {
			  starts_counted.insert(iter->second);
			  best_c++;
				// cout << "best_l " << best_l << " best_c " << best_c << endl;
			}
		}

		if (new_runs.count(PII(m, INF)) == 0) {
		  new_runs[PII(m, INF)] = i;
		}
		if (new_runs.count(PII(INF, n)) == 0) {
		  new_runs[PII(INF, n)] = i;
		}

		runs = new_runs;
	}

	cout << best_l << " " << best_c;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t + 1 << ": ";
		solve();
		cout << endl;
  }
  return 0;
}
