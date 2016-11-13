// TODO: Hypothesis: It must consist of complete bi-partite graphs.
// I could've also precomputed this stuff for N=4 :/

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

int N;

// Machines are colums
bool e(int B, int i, int j) {
  return (1<<(i*N+j))&B;
}

bool check(int B) {
  // Each machine has at least one mechanic.
  REP(j, N) {
    bool has = false;
    REP(i, N) has = has && e(B,i,j);
    if (!has) return false;
  }

  // Each worker must always have a choice, otherwise they can be "chessed out".
  // YOLO neighbors of neigbors
  REP(i, N) {
    int E=0;
    REP(j, N) E+=e(B,i,j);
    set<int> neigh;
    REP(j, N) if(e(B,i,j)) REP(ni, N) if(e(B,ni,j)) neigh.insert(ni);
    if (neigh.size() > E) return false;  // YOLO
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    cin >> N;
    int B = 0;
    int b=0;
    REP(i, N) {
      string S;
      cin >> S;
      REP(s, S.size()) B += (S[s]-'0')*(1<<b);
      b++;
    }

    int result = N*N;
    REP(C, (1<<(N*N))) if((C&B)==B) {
//      printf("Try %x %x\n", C, B);
      int ones=0;
      REP(i, N*N) ones += ((C^B)&(1<<i));
      if (ones < result && check(C)) result = ones;
    }

    cout << result << endl;
  }
  return 0;
}
