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
typedef pair<int, int> PII; 

string solve(){
  string s; 
  LLI x;
  cin >> s >> x; 
  LLI n=s.size(); 
  x--; 
  
  LLI m=1; 
  LLI p=n;
  LLI t=0;  
  
  while(t < x/n){
    t += p; 
    p *= n;
    m++; 
    
    //cout << m << ":" << p << "," << t << endl; 
  }
  
  vector<LLI> P; 
  x -= t; 
  
  REP(i, m){
    P.push_back(x % n); 
    x /= n; 
  }
  reverse(P.begin(), P.end()); 
  
  string result;
  REP(i, P.size()){
    result += s[P[i]]; 
  }
  return result; 
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }
  return 0; 
}
