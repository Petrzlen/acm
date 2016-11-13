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
typedef pair<int, PII> PIII; 

int toint(string time){
  return (time[0] - '0') * 10 * 60
       + (time[1] - '0') * 60
       + (time[3] - '0') * 10 
       + (time[4] - '0') * 1;
}

string tostring(int time){
  string result = "00:00";
  result[0] = ((char) ((time / 600) + '0'));
  result[1] = ((char) (((time / 60)%10) + '0'));
  result[3] = ((char) (((time / 10)%6) + '0'));
  result[4] = ((char) (((time / 1)%10) + '0'));
  return result; 
}

//A -> (B,C,D) 
//train goes from C->D starting at B arriving at A 
vector<PIII> T[1440]; 
//A -> (B,C)
//departing at A one could arrive from B to end at time C 
vector<PII> S[1440]; 

int main(){
  int N;
  cin >> N; 
  vector<int> A(N, -1); 
  
  REP(a, N){
    int m;
    cin >> m; 
    REP(i, m){
      string s1, s2;
      int t; 
      cin >> s1 >> s2 >> t;
      T[toint(s2)].push_back(PIII(toint(s1), PII(a, t-1))); 
      //cout << toint(s1) << " " << toint(s2) << endl;
    }
  }
  
  vector<PII> result; 
  int latest = 1440; 
  for(int t=1439; t>=0; t--){
    A[N-1]=t; 
    
    REP(di, S[t].size()){
      //int ta = t; 
      int tb = S[t][di].second; 
      int sa = S[t][di].first; 
      //int sb = N-1; 
      
      if(A[sa]<0 || tb < A[sa]) A[sa] = tb; 
    }
    
    REP(ai, T[t].size()){
      PIII p = T[t][ai]; 
      int ta = p.first;
      //int tb = t; 
      int sa = p.second.first; 
      int sb = p.second.second; 
      
      if(A[sb]<0) continue;
      S[ta].push_back(PII(sa,A[sb])); 
    }
    
    if(A[0]>=0 && A[0]<latest){
      result.push_back(PII(t, A[0])); 
      latest = A[0]; 
    }
  }
  
  reverse(result.begin(), result.end()); 
  cout << result.size() << endl;
  REP(i, result.size()){
    //cout << result[i].first << " " << result[i].second << endl;
    cout << tostring(result[i].first) << " " << tostring(result[i].second) << endl;
  }

  return 0; 
}
