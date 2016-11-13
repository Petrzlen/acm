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
#define M 512

unsigned int P[2][M][M]; 
unsigned int B[2][M][M]; 

int main()
{
  REP(z, 2) REP(i, M) REP(j, M) P[z][i][j] = 0; 
  P[0][0][0] = 1; 
  
  string s; 
  cin >> s; 
  
  REP(k, s.size()){
    int a = (s[k] == 'a'); 
    int b = (s[k] == 'b'); 
      
    for(int i=s.size()/2; i>=0; i--) for(int j=s.size()/2; j>=0; j--){
      P[b][i+a][j+b] = (P[0][i][j] + P[1][i][j]) % MOD; 
    }
  }
  
  unsigned int result = 0; 
  
  REP(k, M) result = (result + ((P[0][k][k] + P[1][k][k]) % MOD)) % MOD; 
  
  //REP(z, 2) REP(i, (s.size()+1)/2) REP(j, (s.size()+1)/2) cout << "["<<z<<"]["<<i<<"]["<<j<<"] = " << P[z][i][j] << endl; 
  
  cout << result << endl;
  
	return 0;
}
