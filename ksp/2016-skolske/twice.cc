#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define REP(i, to) for (int i = 0; i < to; ++i)
#define MAX 3

void dec(vector<int>& C, vector<int>& D, int i) {
 // C[D[i]]--;
  D[i] = (D[i] + 10 - 1) % 10;
 // C[D[i]]++;
}

void vypluj(vector<int>& D) {
  REP(i, D.size()) cout << D[i];
  cout << endl;
}

int main() {
  int N;
  cin >> N;
  REP(i, N) {
    string s;
    cin >> s;
    if (s.size() > 20) {
      cout << "99887766554433221100" << endl;
      continue;
    }
    if (s.size() <= 2) {
      cout << s << endl;
      continue;
    }
    // Now there exists a purple number with the same digit length.
    // Nope: 1000, pipkos, "0" is the bad guy.
    vector<int> D(s.size());
    REP(i, s.size()) D[i] = s[i] - '0';

    bool pipkos = true;
    while (pipkos) {
      vector<int> C(10, 0);
      pipkos = false;
//      vypluj(D);
      for (int i = 0; i < D.size() ; i++) {
        C[D[i]]++;
        if (C[D[i]] >= MAX) {
          pipkos = true;
//          cout << "pipkos at " << i << " for digit " << D[i] << endl;
            for (int j = i + 1; j < D.size(); ++j) {
             // C[D[j]]--;
              D[j] = 9 - (j - i - 1) / 2;
             // C[D[j]]++;
            }
          if (D[i] == 0) { // bad guy spotted
            while (i > 0 && D[i] == 0) {
              dec(C, D, i);
              i--;
            }  
            dec(C, D, i);
// "i" should be NOT used untul next while(pipkos)
            if (D[0] == 0) {
              D = vector<int>(D.begin() + 1, D.end());
              // C[0]--;
            }
          } else {
            dec(C, D, i);
          }
          break;
        }
      }
    }
    vypluj(D);  // D.size() > 2, i.e. 100 at minimum.
  }

  return 0;
}
