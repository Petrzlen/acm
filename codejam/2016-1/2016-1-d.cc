#include <iostream>
#include <set>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

int main() {
  int T, N;
  cin >> T;
  REP(t, T) {
    string s;
    cin >> s;
    s += '+';
    int c = 0;
    REP(i, s.size() - 1) c += s[i] != s[i+1];
    cout << "Case #" << t+1 << ": " << c << endl;
  }
  return 0;
}
