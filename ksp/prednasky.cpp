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

LLI mod = 1000000007; 

LLI B[50][50]; 
LLI binom(LLI n, LLI k){
  if(n < 0 || k < 0) return 0;
  if(n < k) return 0;
  return B[n][k]; 
}

LLI T[50]; 

int main(){
  B[0][0]=1;
  REP(i, 50) REP(j, 50) if(!(i==0 && j==0)) B[i][j] = (binom(i-1,j-1) + binom(i-1,j)) % mod; 
  
  T[0]=1;
  REP(i, 49) T[i+1] = (T[i] * 2) % mod;
  
  //REP(i, 4) REP(j, 4) cout << i <<"," << j << "=" << binom(i, j) << endl;

  LLI P, S;
  cin >> P >> S; 
  
  // po prednaske i bolo zatial na nejakej prednaske j a na minulej k
  LLI R[50][50][50];
  REP(i, 50) REP(j, 50) REP(k,50) R[i][j][k] = 0; 
  R[0][0][0]=1; 
  
  for(int p=1; p<=P; p++) REP(a, S+1) REP(b, S+1) { 
    if(b==0 && p>1) continue; //niekto musel byt minule 
  
    for(int pok=0; pok<=b; pok++) for(int nov=0; nov<=(S-a); nov++){
      int na=a+nov;
      int nb=pok+nov; 
      R[p][na][nb] = (
        R[p][na][nb] + (R[p-1][a][b] * binom(b, pok) % mod) * binom(S-a, nov)
      ) % mod; 
    }
  }
  
  //REP(i, P+1) REP(j, S+1) REP(k, S+1) cout << i << "," << j << "," << k << "=" << R[i][j][k] << endl;
  
  LLI result=0;
  for(int s=1; s<=S; s++) result = (result + R[P][S][s]) % mod; //po poslednej prednaske vsetci museli byt niekde 
  cout << result << endl;
  
  return 0; 
}
