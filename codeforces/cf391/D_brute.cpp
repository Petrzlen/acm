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
typedef pair<LLI, LLI> PII; 
typedef pair<LLI, PII> PIII; 
PIII zero(0,PII(0,0)); 

LLI cross(PIII& v, PIII& h){
  if(v.second.second < h.first || h.first < v.second.first) return 0; 
  if(h.second.second < v.first || v.first < h.second.first) return 0; 
  
  return min(
    min(v.first - h.second.first, h.second.second - v.first),
    min(h.first - v.second.first, v.second.second - h.first)
  ); 
}

int main(){
  int N, M;
  cin >> N >> M; 
  
  vector<PIII> V(N, zero), H(M, zero);
  REP(i, N) {
    cin >> V[i].first >> V[i].second.first >> V[i].second.second; 
    V[i].second.second += V[i].second.first; 
  }
  REP(i, M) {
    cin >> H[i].second.first >> H[i].first >> H[i].second.second;   
    H[i].second.second += H[i].second.first;   
  }
  
  LLI result = 0;
  REP(i, N) REP(j, M) result = max(result, cross(V[i], H[j])); 
  cout << result << endl;
  
  return 0; 
}
