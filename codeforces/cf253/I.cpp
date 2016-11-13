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
  vector<PII> V[3]; 
  int N, A, B;
  cin >> N >> A >> B; 
  
  REP(i, N){
    int t,f;
    cin >> t >> f;
    V[t-1].push_back(PII(f, i+1)); 
  }
  
  REP(i, 3) sort(V[i].begin(), V[i].end()); 
  int a = min(A, (int)V[0].size()); 
  int b = min(B, (int)V[1].size()); 
  int c = min(A-a + B-b, (int)V[2].size()); 
  
  while(c<V[2].size()){
    bool was = false;
    if(a>0 && (b == 0 || V[0][a-1].first >= V[1][b-1].first) && V[0][a-1].first > V[2][c].first){
      a--;
      c++; 
      was = true;
    }
    else {
      if(b>0 && (a==0 || V[1][b-1].first >= V[0][a-1].first) && V[1][b-1].first > V[2][c].first){
        b--;
        c++;
        was = true;
      } 
    }
    if(!was) break; 
  }
  
  int sum=0;  
  REP(i, a) sum += V[0][i].first; 
  REP(i, b) sum += V[1][i].first; 
  REP(i, c) sum += V[2][i].first; 
 
  cout << a+b+c << " " << sum << endl; 
  
  int s=1; 
  REP(i, a) cout << V[0][i].second << " " << s++ << endl;
  REP(i, c) cout << V[2][i].second << " " << s++ << endl;
  s = max(s, A+1); 
  REP(i, b) cout << V[1][i].second << " " << s++ << endl;
  
  return 0; 
}
