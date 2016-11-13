#include <iostream>
#include <set>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

int main() {
  int T, N;
  cin >> T;
  REP(t, T) {
    cin >> N;
    cout << "Case #" << t+1 << ": ";
    if (N==0) {cout << "INSOMNIA" << endl; continue;}
    set<int> D;
    int n = 0;
    while (D.size() < 10) {
      n += N;
      int c = n;
      while (c > 0) {D.insert(c%10); c /= 10;}
    }
    cout << n << endl;
  }
  return 0;
}
