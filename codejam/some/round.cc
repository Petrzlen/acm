#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)
#define M 100

// votes needed, for language
typedef pair<int, int> PII;
typedef pair<double, PII> PDII;

int solve() {
  int N, L;
	cin >> N >> L;
	vector<int> langz(L, 0);
	int votes = 0;
	FOR(i, L) {
	  cin >> langz[i];
		votes += langz[i];
	};
	// allocate extra N languages with 0 votes
	FOR(i, N) langz.push_back(0);

	// calculate possible gains if a lang has i votes
  vector<double> gainz;
	FOR(i, N+1) {
	  double perc = 100.0 * (double) i / (double) N;
	  gainz.push_back(round(perc) - perc);
	}

  // if we would add j to a lang i, how much extra gainz we would have
  vector<PDII> pq;
	FOR(j, M) FOR(i, langz.size()) {
	  double gain = (gainz[langz[i]+j+1] - gainz[langz[i]]);
		double gain_per_one = gain / ((double) (j+1));
	  pq.push_back(PDII(gain_per_one, PII(j+1, i)));
	}
	sort(pq.begin(), pq.end(), greater<PDII>());

	int budget = N - votes;
	set<int> used;
	FOR(k, pq.size()) {
	  if (budget <= 0) break;
		PDII m = pq[k];
		int lang = m.second.second;
		int c = m.second.first;
		if (used.find(lang) != used.end()) continue;
		if (m.second.first > budget) continue;

		used.insert(lang);
		budget -= c;
		langz[lang] += c;
		// cerr << "lang " << lang << " c " << c << " gainz " << m.first << endl;
	}

  int total_percent = 0;
	FOR(i, langz.size()) {
	  total_percent += round(100.0 * (double) langz[i] / (double) N);
	}
	return total_percent;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t + 1 << ": " << solve() << endl;
  }
  return 0;
}
