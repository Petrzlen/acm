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

LLI ou(LLI n){
  LLI res=0; 
  while(n > 0) {res += n%10; n/=10;}
  return res; 
}

LLI pow(LLI x, LLI y){
  LLI res = 1; 
  REP(i, y) res *= x; 
  return res; 
}

int main(){
  int n; 
  cin >> n; 
 
//  LLI to = pow(10, n); 
//  vector<LLI> cs(n*10, 0); 
//  for(LLI i=pow(10, n-1); i<to ; i++){cs[ou(i)]++;}
 
  vector<vector<LLI> > R(n+1, vector<LLI>(n*9+1, 0)); 
  for(int j=1; j<10; j++) R[1][j] = 1; 
  for(int i=2; i <= n ; i++) for(int s=1; s<= n*9 ; s++) for(int p=max(1, s-9) ; p<=s ; p++) R[i][s] += R[i-1][p]; 
  
  //for(int r=1; r<=n*9 ; r++) cout << R[n][r] << " " << cs[r] << endl;
  for(int r=1; r<=n*9 ; r++) cout << r << " " << R[n][r] << endl;
   
  return 0; 
}
