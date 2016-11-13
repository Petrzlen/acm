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

int gcd(int x, int y){
//cout << "gcd " << x << "," << y << endl; 
  if(x<y) return gcd(y,x); 
  if(y == 0) return x; 
  if(y == 1) return 1; 
  return gcd(y, x%y); 
}

int main(){
  int n; 
  cin >> n;
  
  map<int, LLI> C; 
  map<int, LLI> S; 
  
  REP(i, n) {
    int x; 
    cin >> x; 
    map<int, LLI> M; 
    for(map<int, LLI>::iterator iter = S.begin() ; iter != S.end() ; iter++) {
      M[gcd(iter->first, x)] += iter->second; 
    }
    M[x]++; 
    S=M; 
    for(map<int, LLI>::iterator iter = S.begin() ; iter != S.end() ; iter++) C[iter->first]+=iter->second; 
    
    //cout << x << ":" << S.size() << endl;
  }
  
//  for(map<int, LLI>::iterator iter = S.begin() ; iter != S.end() ; iter++) cout << iter->first << "->" << iter->second << endl;
  
  //================
  int q; 
  cin >> q; 
  REP(i, q) {int y; cin >>y; cout << C[y] << endl;}  
  
  return 0; 
}
