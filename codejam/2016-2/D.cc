#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

// TODO(petrzlen): Should've implemented fraction probabilities :(
// YOLO YOLO YOLO
double prob(const vector<double>& V, int K) {
  vector<double> P(K+1, 0.0);
  P[0]=1.0;
  REP(k, K)for(int p=K; p>=0; p--) {
    P[p] = (1.0-V[k])*P[p] + ((p!=0)?V[k]*P[p-1]:0.0);
  }
//  REP(k, K+1) cout << " " << k << ": " << P[k] << endl;
  return P[K/2];
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    int N, K;
    cin >> N >> K;
    vector<double> V(N, 0.0);
    REP(i, N) cin >> V[i];

    sort(V.begin(), V.end());
    vector<double> YOLO;
    REP(i, K/2) {
      YOLO.push_back(V[i]);
      YOLO.push_back(V[N-1-i]);
    }
    printf("%.8f\n", prob(YOLO, K));
  }
  return 0;
}

/*
int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    int N, K;
    cin >> N >> K;
    vector<double> V(N, 0.0);
    REP(i, N) cin >> V[i];

    double result = 0.0;
    vector<double> T(N, 0.0);
    REP(b, (1<<N)) {
      int c = 0;
      REP(i, N) if ((1<<i)&b) T[c++]=V[i];
      if (c == K) {
//        cout << "test:"; REP(i, K) cout << " " << T[i]; cout << endl;
        double p = prob(T, K);
        result = max(result, p);
      }
    }
 //   cout << result << endl;
    printf("%.8f\n", result);
  }
  return 0;
}

*/
