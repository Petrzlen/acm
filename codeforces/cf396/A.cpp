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

#define MOD 1000000007
#define MAX 100000
vector<int> Q; 

void build_primes(){
  vector<bool> B(MAX, true); 
  REP(i, MAX) B[i] = true; 
  B[0] = B[1] = false; 
  for(int i=2; i<MAX ; i++){
    if(B[i]) {
      for(int j=i*2; j<MAX ; j += i) {
        B[j] = false; 
      }
    }
  }
  REP(i, B.size()) if(B[i]) Q.push_back(i); 
  
  //cout << "==Q " << Q.size() << endl;
  //REP(i, Q.size()) cout << Q[i] << endl;
}

map<int, int> factor(int x){
  map<int, int> result; 
  
  REP(i, Q.size()){
    if(x == 0) break; 
  
    while(x % Q[i] == 0){
      result[Q[i]]++;
      x /= Q[i]; 
    }
  }
  if(x != 0) result[x] += 1; 
  return result; 
}

int main(){
  build_primes(); 
  
  int n; 
  cin >> n; 
  
  map<int, int> M; 
  REP(i, n){
    int x;
    cin >> x; 
    if(x <= 1) continue; 
    
    map<int, int> f = factor(x); 
    for(map<int, int>::iterator iter = f.begin() ; iter != f.end() ; iter++){
      M[iter->first] += iter->second; 
    }
  }
  
  vector<int> P(20000, 0); 
  for(map<int, int>::iterator iter = M.begin() ; iter != M.end() ; iter++){
    //cout << "==M " << iter->first << ": " << iter->second << endl;
    if(iter->first <= 1) {
      continue; 
    }
    int si = iter->second; 
    P[si + n - 1]++; 
    P[n-1]--; 
    P[si]--; 
  }
  //cout << "==P" << endl;
  //REP(i, P.size()) if(P[i] != 0) cout << i << ": " << P[i] << endl;
  
  vector<LLI> R(P.size(), 0); 
  int s = 0; 
  for(int p=P.size() - 1 ; p >= 2 ; p--){
    if(P[p] == 0 && s == 0) continue; 
    s += P[p]; 
    
    map<int, int> f = factor(p); 
    for(map<int, int>::iterator iter = f.begin() ; iter != f.end() ; iter++){
      if(iter->first > 1){
        R[iter->first] += iter->second * s; 
      }
    }
  }
  //cout << "==R" << endl;
  //REP(i, R.size()) if(R[i] != 0) cout << i << ": " << R[i] << endl;
  
  LLI result = 1; 
  REP(i, R.size()) REP(j, R[i]) result = (result * ((LLI) i)) % MOD;
  cout << result << endl;
  
  
  return 0; 
}
