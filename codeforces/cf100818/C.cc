#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define LOG 1

using namespace std;

typedef long long LLI;
#define REP(i, to) for (int i=0; i < to; ++i)

set<LLI> primes;
map<LLI, vector<double> > state;
vector<LLI> divisors;

void make_primes(LLI N) {
  vector<bool> p(N, true);
  p[0]=false;
  p[1]=false;
  for (LLI j=2; j<N; ++j) {
    if (p[j]) {
      if (LOG && j < 50) cout << "p: " << j << endl;
      primes.insert(j);
      for (LLI i=j; i*j<N; ++i) p[i*j]=false;
    }
  }
}

vector<LLI> get_divisors(LLI N) {
  vector<LLI> res(1,1);
  for (LLI p : primes) {
    int e = 0;
    while (N % p == 0) {
      N /= p;
      e++;
    }
    for (int r = res.size() - 1; r >= 0; r--) {
      LLI m = 1;
      REP(i, e) {
        m *= p;
        res.push_back(res[r] * m);
      }
    }
  }
  if (N > 1) {
    res.push_back(N);
    primes.insert(N);
  }
  return res;
}

inline double get_val(vector<double>* V, int i) {
  if (i >= V->size()) return 1.0;
  return (*V)[i];
}

vector<double>* solve(LLI n) {
  if (LOG) cout << "solve " << n << endl;
  if (state.count(n)) return &state[n];
  if (primes.find(n) != primes.end()) {
    state[n] = vector<double>(1, 1.0);
    return &state[n];
  }

  vector<double> res(60, 0.0);
  double ways = 0.0;
  REP(i, divisors.size()) {
    LLI d = divisors[i];
    if (d == 1 || d == n || n % d != 0) continue;
    if (n / d < d) break; // assuming it's sorted
    if (LOG) cout << n << " -> " << d << "," << n/d << endl;
    double mul = (n / d == d) ? 0.5 : 1.0;
    ways += mul;
    vector<double>* a = solve(d);
    vector<double>* b = solve(n/d);
    //int to = 60;
    REP(j, 60) {
      res[j + 1] += mul * get_val(a,j) * get_val(b,j);
    }
  }
  if (ways == 0) cerr << "SHIT " << n << endl;
  REP(r, res.size()) res[r] /= ways;

  state[n] = res;
  return &state[n];
}

int main() {
  make_primes(1000000);
  LLI T;
  cin >> T;
  REP(t, T) {
    state.clear();
    LLI n;
    cin >> n;
    divisors = get_divisors(n);
    sort(divisors.begin(), divisors.end());
    if (LOG) REP(d, divisors.size()) cout << "d: " << divisors[d] << endl;
    vector<double>* prob = solve(n);
    double res = 0.0;
    REP(i, prob->size() + 10) res += (i + 1) * (get_val(prob, i+1) - get_val(prob, i));
    cout << res << endl;
    if (LOG) {
      for (const auto& p : state) {
        cout << p.first << ":";
        for (LLI v : p.second) cout << " " << v;
        cout << endl;
      }
    }
  }

  return 0;
}
