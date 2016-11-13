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

int main(){
  int N, D; 
  cin >> D >> N; 
  string S;
  cin >> S; 
  
  vector<int> P(S.size()+1, 0); 
  REP(i, S.size()) P[i+1] = P[i] + (S[i]=='D'); 
  
  int mi=S.size(); 
  int ma=0; 
  REP(i, N-D+1) {
    int d1=P[i]; 
    int d2=P[i+D]; 
    mi = min(mi,d2-d1);
    ma = max(ma,d2-d1); 
  } 
  
  cout << mi << endl << ma << endl;
  
  return 0; 
}
