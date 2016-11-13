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
#include <iterator> 

using namespace std;

#define REP(i, to) for(LLI i=0; i<to; i++)

typedef long long int LLI;
typedef pair<LLI, LLI> PII; 

LLI A, B, P; 
vector<LLI> result(1, -1);
int days = -1; 
  
LLI solve(vector<pair<PII, LLI> >& S, vector<PII>& D, LLI from, LLI to){
  LLI d = ((from + to) / 2) - 1; 
  LLI s = (D.size() + d - 1) / d;
  
  //cout << "solve(" << from <<"," << to << ") d="<<d << " s=" << s << endl;
  
  vector<LLI> students; 
  vector<bool> selected(S.size(), false); 
  LLI solved = 0; 
  LLI passes = 0; 
    
  REP(i, s){
    pair<PII, LLI> tf(PII(D[solved].first, 0),0);
    vector<pair<PII, LLI> >::iterator siter = lower_bound(S.begin(), S.end(), tf);
    LLI si = distance(S.begin(), siter); 
      
    //cout << "  lower_bound=" << si << endl;
      
    while(si < S.size() && selected[si]) si++; 
      
    if(si == S.size()) break; 
      
    //cout << "  days=" << d << " student=" << S[si].second << endl;

    selected[si] = true; 
    passes += S[si].first.second; 
    solved += d; 
    students.push_back(S[si].second); 
      
    if(solved >= D.size()) break; 
  }
    
  //cout << "solved=" << solved << " passes=" << passes << endl;
  //cout << "D.size()=" << D.size() << " P=" << P << endl;
    
  if(solved >= D.size() && passes <= P) {
    //cout << "FAJNE" << endl;
    result = students; 
    days = d; 
    if(from + 1 < to) return solve(S,D,from, d+1);
  }
  else{
    if(from + 1 < to) return solve(S,D,d+1, to);  
  }
}

int main(){
  cin >> A >> B >> P; 
  
  vector<PII> D(B,PII(0,0)); 
  REP(i, B) {
    cin >> D[i].first;
    D[i].second = i+1; 
  }
  sort(D.begin(), D.end(), greater<PII>());
  
  vector<pair<PII, LLI> > S(A, pair<PII,LLI>(PII(0,0), 0)); 
  REP(i, A) cin >> S[i].first.first; 
  REP(i, A) cin >> S[i].first.second; 
  REP(i, A) S[i].second = i+1; 
  
  sort(S.begin(), S.end()); 
  
  //cout << "days=" << D.size() << " students=" << S.size() << endl;
  
  solve(S, D, 1, B+2); 
  
  if(result[0] >= 0){
    cout << "YES" << endl;
    
    vector<LLI> R(D.size(), 0); 
    REP(r, result.size()){
      REP(i, days){
        LLI p = r*days + i; 
        if(p < D.size()) R[D[p].second-1] = result[r];  
      }
    }
    REP(i, R.size()) {
      if(i!=0) cout << " ";
      cout << R[i];
    }
    cout << endl;
  }
  else{
    cout << "NO" << endl; 
  }
  
  return 0; 
}
