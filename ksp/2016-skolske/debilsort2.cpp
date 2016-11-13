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

LLI T(int n){
  if(n<=1) return 1;
  LLI sum=2*n;
  REP(i, n-1) sum += T(i+1); 
  return sum; 
}

#define MOD 1000000000

int main(){
  set<LLI> W;
  LLI x = 5;
  map<LLI, int> M; 
  map<int, LLI> Mb;
  int i=2; 
  while(W.find(x) == W.end()){
    W.insert(x); 
    Mb[i]=x;
    M[x]=i++; 
    x = (x*2 + 2) % MOD; 
  }
  cout << x << endl;
  cout << W.size() + 1 << "/" << M[x] << endl; 
  cout << Mb[1562513] << endl;
  cout << Mb[1562512] << endl;
  cout << Mb[1562511] << endl;
  cout << Mb[1562510] << endl;
  cout << Mb[1562509] << endl;
  cout << Mb[1562508] << endl;
  cout << Mb[1562507] << endl;
  cout << Mb[1562506] << endl;
  cout << Mb[1562505] << endl;
  
  return 0; 
}
