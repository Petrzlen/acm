#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define LOG 0
// Cause 2^35 > 10^10
#define STATE_SIZE 35
// Cause 2*3*5*7*11*13*17*19*23*29*31/10^10 > 1
#define NUM_SIZE 11

using namespace std;

typedef long long LLI;
#define REP(i, to) for (int i=0; i < to; ++i)

typedef vector<int> NUM;
vector<LLI> primes;
map<LLI, vector<double> > state;
LLI hash_cache[NUM_SIZE][STATE_SIZE];

// declarations
vector<double>* solve(const NUM&, LLI);

// definitions
void make_primes(LLI N) {
  vector<bool> p(N, true);
  p[0]=false;
  p[1]=false;
  for (LLI j=2; j<N; ++j) {
    if (p[j]) {
      if (LOG && j < 20) cout << "p: " << j << endl;
      primes.push_back(j);
      for (LLI i=j; i*j<N; ++i) p[i*j]=false;
    }
  }
}

void init_hash_cache() {
  REP(i, NUM_SIZE) {
    LLI res = 1;
    REP(j, STATE_SIZE) {
      hash_cache[i][j] = res;
      res *= primes[i];
    }
  }
}

LLI my_hash(const NUM& number) {
  LLI res = 1;
  REP(i, number.size()) {
    // if (number[i] == 0) break;
    // REP(j, number[i]) res *= primes[i];
    res *= hash_cache[i][number[i]];
  }
  return res;
}

NUM get_divisors(LLI N) {
  NUM res;
  for (LLI p : primes) {
    int e = 0;
    while (N % p == 0) {
      N /= p;
      e++;
    }
    if (e != 0) {
      res.push_back(e);
    }
  }
  if (N > 1) {
    res.push_back(1);
    primes.push_back(N);
  }
  sort(res.begin(), res.end(), greater<int>());
  return res;
}

void iter(const NUM& orig, int i, NUM* cur, vector<double>* res, double* ways) {
  if (i >= orig.size()) return;
  // int to = (i == 0) ? orig[0] : min((*cur)[i-1],orig[i]);
  int to = orig[i];
  if (LOG) cout << "iter " << i << " " << to << endl;

  for ((*cur)[i] = 0; (*cur)[i] <= to; (*cur)[i]++) {
    if (LOG) cout << "ci " << i << " " << (*cur)[i] << endl;
    // TODO speed up (reuse d?)
    // zeros are fine (hash value)
    if (i + 1 == orig.size()) {
      NUM d2;
      REP(j, orig.size()) d2.push_back(orig[j] - (*cur)[j]);
      sort(d2.begin(), d2.end(), greater<int>());

      NUM d1 = *cur;
      sort(d1.begin(), d1.end(), greater<int>()); // TODO speed up
      if (d1[0] == 0 || d2[0] == 0) continue;  // not a proper divisor, i.e. 1

      LLI ha = my_hash(d1);
      LLI hb = my_hash(d2);
      if (ha > hb) continue;
      double w = (ha == hb) ? 1.0 : 2.0;

      vector<double>* a = solve(d1, ha);
      vector<double>* b = solve(d2, hb);
      if (LOG) cout << my_hash(orig) << "mul: " << my_hash(d1) << " " << my_hash(d2) << endl;
      REP(j, STATE_SIZE-1) (*res)[j+1] += w * (*a)[j] * (*b)[j];
      *ways += w;
    } else {
      iter(orig, i+1, cur, res, ways);
    }
  }
  (*cur)[i] = 0;
}

vector<double>* solve(const NUM& num, LLI h) {
  if (LOG) cout << "solve " << h << endl;
  if (state.count(h)) return &state[h];
  // Base cases:
  // 0: safety
  // 2: equivalent to only prime, i.e. vector {1}
  if (h == 0 || h == 2) {
    state[h] = vector<double>(STATE_SIZE, (h == 2) ? 1.0 : 0.0);
    return &state[h];
  }

  NUM cur(num.size(), 0);
  vector<double> res(STATE_SIZE, 0.0);
  double ways = 0.0;

  iter(num, 0, &cur, &res, &ways);
  if (ways == 0.0) cerr << "SHIT ways is zero" << endl;
  if (LOG) cout << "ways(" << h << "): " << ways << endl;
  REP(r, res.size()) res[r] /= ways;

  state[h] = res;
  return &state[h];
}

int main() {
  make_primes(1000000);
  init_hash_cache();
  LLI T;
  cin >> T;
  REP(t, T) {
  //  state.clear();  // Keep it between test cases
    LLI n;
    cin >> n;
    NUM divisors = get_divisors(n);
    if (LOG) REP(d, divisors.size()) cout << "e: " << divisors[d] << endl;
    vector<double>* prob = solve(divisors, my_hash(divisors));
    double res = 0.0;
    REP(i, prob->size() - 1) res += (i + 1) * (((*prob)[i+1]) - ((*prob)[i]));
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
