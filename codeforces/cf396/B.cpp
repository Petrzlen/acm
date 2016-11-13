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
}

void solve(int n){
  vector<int> pp(Q.size(), 0); 
  int r = 0; 
  
  for(int i=2; i<=n ; i++){
    while(Q[r+1] <= n) r++; 
    pp[r]++;
    pp[r+1]--; 
  }
  
  cout << "==solve " << n << endl;
  REP(i, Q.size()) if(pp[i] != 0) cout << Q[i] << ": " << pp[i] << endl;
}

int main(){
  build_primes(); 
  
  for(int n=2; n < 10 ; n++) solve(n); 
  
  return 0; 
}
