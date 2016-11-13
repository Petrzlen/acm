#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

#define MAX 13
string D[3][MAX+1];
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
map<PIII, string> M;

void gen() {
  D[0][0]="P";
  D[1][0]="R";
  D[2][0]="S";
  REP(i,MAX) {
//    cout << i << endl;
    D[0][i+1] = min(D[0][i], D[1][i]) + max(D[0][i], D[1][i]);
    D[1][i+1] = min(D[1][i], D[2][i]) + max(D[1][i], D[2][i]);
    D[2][i+1] = min(D[2][i], D[0][i]) + max(D[2][i], D[0][i]);
  }
  REP(j, MAX+1) REP(i, 3) {
    int p=0, r=0, s=0;
    REP(k,D[i][j].size()) {
      char c=D[i][j][k];
      p += (c=='P');
      r += (c=='R');
      s += (c=='S');
    }
//    cout << p << "," << r << "," << s << endl;
    M[PIII(p,PII(r,s))]=D[i][j];
  }
}

int main() {
  gen();

  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";;
    int N,R,P,S;
    cin >> N >> R >> P >> S;
    string res = M[PIII(P,PII(R,S))];
    if (res.empty()) cout << "IMPOSSIBLE" << endl;
    else cout << res << endl;
  }
  return 0;
}


/*
char fight(char a, char b) {
  if(a=='P'&&b=='R') return 'P';
  if(a=='R'&&b=='P') return 'P';
  if(a=='P'&&b=='S') return 'S';
  if(a=='S'&&b=='P') return 'S';
  if(a=='S'&&b=='R') return 'R';
  if(a=='R'&&b=='S') return 'R';
  cout << "SHIT";
  return 'O';
}

bool run_tourney(const string& T) {
//  cout << "run_tourney " << T << endl;
  if(T.size() <= 1) return true;
  REP(i, T.size()/2) if(T[2*i]==T[2*i+1]) return false;
  string Tnext(T.size()/2, 'O');
  REP(i, T.size()/2) Tnext[i] = fight(T[2*i], T[2*i+1]);
  return run_tourney(Tnext);
}

string check_all(int R, int P, int S) {
  int N=R+P+S;
  string B = string(S, 'S') + string(R, 'R') + string(P, 'P');
  string result = "";
  int V[N]; REP(i,N) V[i]=i;
  do {
    string T(N, '0');
    REP(i, N) T[i]=B[V[i]];
//    cout << "Trying" << T << endl;
    if (result.empty() || T < result) {
      if (run_tourney(T)) {
        result = T;
      }
    }
  } while (next_permutation(V, V+N));
  return result;
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    int N,R,P,S;
    cin >> N >> R >> P >> S;
    string s = check_all(R, P, S);
    if (s.empty()) cout << "IMPOSSIBLE" << endl;
    else cout << s << endl;
  }
  return 0;
}

*/
