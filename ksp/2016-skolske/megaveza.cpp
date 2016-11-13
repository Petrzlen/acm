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

LLI gcd(LLI a, LLI b){
  if(a<b) return gcd(b,a); 
  if(b==1) return 1; 
  if(a%b==0) return b; 
  return gcd(b, a%b); 
}

int main(){
  int N; 
  cin >> N; 
  
  vector<LLI> IN(N, 0); 
  REP(i, N) cin >> IN[i]; 
  
  LLI g = IN[0];
  for(int i=1; i<N; i++) g = gcd(g, IN[i]); 
  LLI r = 0; 
  REP(i, N) r += IN[i] / g; 
  
  cout << r << endl;
   
  return 0; 
}
