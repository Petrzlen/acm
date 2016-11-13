#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define REP(i, to) for (int i = 0; i < to; ++i)

int main() {
  int N;
  cin >> N;
  if (N == 1) cout << "1A 0X\n1B 0X\n";
  else {
    REP(i, 2*N) cout << ((i%N)+1) << ((i<N)?'A':'B') << ((i%2==0)?' ':'\n');
  }

  return 0;
}
