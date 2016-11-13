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

char M[512][512]; 

int p(int i, int j){
  return 
  (M[i-1][j] == M[i][j]) + 
  (M[i+1][j] == M[i][j]) + 
  (M[i][j-1] == M[i][j]) + 
  (M[i][j+1] == M[i][j]); 
}

int main(){
  int r,c;
  int s; 
  cin >> r >> c >> s;
  REP(i, r+2) REP(j, c+2) M[i][j] = 'Q'; 
   
  REP(i, r) REP(j, c) {
    if(i==0) M[i+1][j+1] = 'a'; 
    else if(i==r-1) M[i+1][j+1] = 'b'; 
    else M[i+1][j+1] = j%2==0 ? 'a' : 'b'; 
  }
  
  for(int t=(r!=1)+1 ; t<s ; t++) {
    bool f=true; 
    for(int i=r-1; i>=0; i--) if(f) for(int j=c-1; j>=0; j--) if(p(i+1, j+1) == 1) {
      f=false; 
      M[i+1][j+1]='a'+t; 
      break;
    }
  }
  
  REP(i, r) {REP(j, c) cout << M[i+1][j+1]; cout << endl;}
  
  return 0; 
}
