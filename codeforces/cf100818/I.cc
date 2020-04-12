#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <unordered_map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

int main(){
  int N, K;
  cin >> N >> K;
  /*
  unordered_map<int,int> M;
  int can = 0;
  int x;
  REP(i, N) {
    scanf("%d", &x);
    ++M[x];
  }
  for (const auto& p : M) {
    if (p.second % K != 0) cout << p.first << endl;
  }
  */

  vector<int> V(N+1);
  REP(i, N) {
    scanf("%d", &V[i]);
  }
  V[N]=1234567890;
  sort(V.begin(), V.end());
  int start = 0;
  REP(i, N+1) {
    if (V[i] != V[start]) {
      if ((start - i) % K != 0) {
        cout << V[start] << endl;
        return 0;
      }
      start = i;
    }
  } 
  
  return 0; 
}
