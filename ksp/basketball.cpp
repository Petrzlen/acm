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

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

int N, M, P; 
  
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
  solve_team(T[0], A);
  solve_team(T[1], A);
}

void solve_team(vector<PII>& S, map<PII, string>& A){
  vector<bool> F(S.size(), false); 
  vector<int> T(S.size(), 0); 
  
  REP(i, min(F.size(), P)) F[i] = true; 
  
  REP(t, m){
    REP(i, F.size()) if(F[i]) T[i]++; 
  
    int mt=0;
    REP(i, F.size()) if(F[i]) mt = max(mt, T[i]); 
    int mi=-1; 
    for(int i=F.size()-1; i>=0; i--)  if(F[i] && T[i] == mt){
      mi = i;
      break; 
    }
    
    int lt=0;
    REP(i, F.size()) if(!F[i]) lt = min(lt, T[i]); 
    int li=-1; 
    REP(i, F.size()) if(!F[i] && T[i] == lt){
      li = i;
      break; 
    }
    cout << "change " << A[S[mi]] << " for " << A[S[li]] << endl;
    
    F[mi] = false; 
    F[li] = true; 
  }
  
  REP(i, min(P, F.size()) if(F[i]) cout << " " << A[S[i]];
}

int main(){
  int T;
  cin >> T;
  REP(i, T) {
    cout << "Case #" << t+1 << ":"; 
    solve(); 
    cout << endl;
  }
  return 0; 
}
