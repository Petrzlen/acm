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

using namespace std;

#define REP(i, to) for(int i=0; (i)<(to); i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

size_t N, M, P; 
vector<PII> R; 
vector<string> RT; 
  
void solve_team(vector<PII>& S){
  vector<int> T(S.size(), 0); 
  vector<bool> F(S.size(), false);
  size_t p = min(P, S.size()); 
  REP(i, p) F[i] = true; 
  
  if(p < S.size()){
    REP(t, M){
      REP(i, F.size()) T[i] += F[i]; 
      vector<PII> V;
      REP(i, F.size()) V.push_back(PII(T[i], i)); 
      sort(V.begin(), V.end()); 
      
      int di = 0;
      int ui = 0;
      REP(i, V.size()) if(F[V[i].second]) di = V[i].second; 
      REP(i, V.size()) if(!F[V[i].second]) {
        ui = V[i].second; 
        break; 
      }
      
      F[di] = false;
      F[ui] = true; 
    }
  }
  
  REP(i, F.size()) if(F[i]) R.push_back(S[i]); 
}
void solve(){
  cin >> N >> M >> P; 
  
  map<PII, string> A;
  vector<PII> S;  
  REP(i, N){
    string s;
    int p, h;
    cin >> s >> p >> h;
    S.push_back(PII(p,h)); 
    A[PII(p,h)] = s; 
  }
  sort(S.begin(), S.end(), greater<PII>()); 
  
  vector<PII> T[2]; 
  REP(i, S.size()) T[i%2].push_back(S[i]); 
  solve_team(T[0]);
  solve_team(T[1]);
  REP(i, R.size()) RT.push_back(A[R[i]]); 
}

int main(){
  int T;
  cin >> T;
  REP(t, T) {
    solve(); 
    
    sort(RT.begin(), RT.end()); 
    
    cout << "Case #" << t+1 << ":"; 
    REP(i, RT.size()) cout << " " << RT[i];  
    cout << endl;
    R.clear(); 
    RT.clear(); 
  }
  return 0; 
}
