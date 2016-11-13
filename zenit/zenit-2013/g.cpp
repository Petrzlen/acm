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

char M[64][64]; 

void vybiel(int i, int j){
  //cout << i << "," << j << ":" << M[i][j] << endl;

  if(M[i][j]=='.') return; 
  M[i][j] = '.'; 
  vybiel(i-1,j);
  vybiel(i+1,j);
  vybiel(i,j-1);
  vybiel(i,j+1);
}
  
int main(){
  int R, C; 
  REP(i, 64) REP(j, 64) M[i][j] = '.';
  
  cin >> R >> C; 
  REP(i, R) {
    string line; 
    cin >> line; 
    REP(j, C) M[i+1][j+1] = line[j]; 
  }
  
  vybiel(1,1);
  
  int result = 0; 
  REP(i, 64) REP(j, 64) result += M[i][j] == '#';
  cout << result << endl;
  
  return 0; 
}
