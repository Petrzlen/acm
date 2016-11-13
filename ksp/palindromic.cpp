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
typedef pair<int, LLI> PII; 

#define MOD 1000000009
#define MAX 2550
LLI S[MAX][MAX]; 

int main(){
  string s;
  cin >> s; 
  REP(i, s.size()) REP(j, s.size()) S[i][j] = -500600; 
  
  REP(k,s.size()) REP(i, s.size()){
    int j=i+k; 
    if(j>=s.size()) break; 
    
    if(i==j) S[i][j]=1;
    else if(i+1==j) S[i][j]=2+(s[i] == s[j]);  
    else {
      S[i][j]=(S[i][j-1]+S[i+1][j]+((s[i]==s[j])?1:MOD-S[i+1][j-1])) % MOD; 
    }
  }
  
  //REP(i,s.size()) REP(j,s.size()) if(i<=j) cout << i << "," << j << ":" << S[i][j] << endl;
  
  cout << S[0][s.size()-1] % MOD << endl;

  return 0; 
}
