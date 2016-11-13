#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

int main() {
  int T, N;
  cin >> T;
  REP(t, T) {
    int N, X;
    cin >> N >> X;
    cout << "Case #" << t+1 << ":" << endl;
    if (N%2==1) {cout << "TODO: implement" << endl; return 0;}
    REP(x, X) {
      string s1, s2;
      REP(b, N/2 - 1) s1 += '0' + bool(x & (1 << b));
      s2 = s1;
      reverse(s2.begin(), s2.end());
      cout << "1" << s2 << s1 << "1";
      REP(n, N-1) cout << " " << n+3;
      cout << endl;
    }
  }
  return 0;
}
