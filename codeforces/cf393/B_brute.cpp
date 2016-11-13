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

typedef unsigned long long int LLI;
typedef pair<LLI, LLI> PII; 

#define MAX 42 
#define INF 123456789123456789ll 
LLI C[3][3]; 
LLI P[MAX]; 

vector<int> repre(LLI pos){
  vector<int> result(3,MAX); 
  REP(i, MAX){
    result[pos%3] = min(result[pos%3], i); 
    pos /= 3; 
  }
  return result; 
}

void sim(map<LLI, LLI>& M, LLI steps){
  REP(s, steps){
    vector<PII> next; 
    for(map<LLI, LLI>::iterator iter = M.begin() ; iter != M.end() ; iter++){
      vector<int> R = repre(iter->first); 
      REP(i, 3) REP(j, 3) if(i != j) if(R[i] < R[j]) {
        next.push_back(PII(iter->first + P[R[j]] - P[R[i]], iter->second + C[i][j])); 
      }
    }
    
    REP(i, next.size()) {
      if(!M.count(next[i].first)) M[next[i].first] = next[i].second; 
      M[next[i].first] = min(M[next[i].first], next[i].second); 
    }
  }
}

int main(){
  LLI N; 
  P[0] = 1; 
  REP(i, MAX-1) P[i+1] = P[i] * 3;  
    
  REP(i, 3) REP(j, 3) cin >> C[i][j]; 
  cin >> N; 

  map<LLI, LLI> M1, M2; 
  M1[0]=0; 
  M2[P[N]]=0; 
  sim(M1, (1 << ((N+4)/2)));
  sim(M2, (1 << ((N+4)/2))); 
  
  LLI result = INF; 
  for(map<LLI, LLI>::iterator iter = M1.begin() ; iter != M1.end() ; iter++){
    vector<int> R = repre(iter->first); 
    cout << "M1 " << iter->first << ": " << iter->second << "("; 
    REP(i, R.size()) cout << R[i] << " ";
    cout << ")"<< endl;
    
    if(M2.count(iter->first)){
      cout << "  match " << iter->second << ": " << M2[iter->first] << endl;
      result = min(result, iter->second + M2[iter->first]); 
    }
  }
  
  cout << result << endl; 
  
  return 0; 
}
