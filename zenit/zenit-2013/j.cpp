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
typedef pair<int, PII> PIII;  

#define M 1024
int H[6] = {1,2,5,10,20,100}; 
bool V[2*M][2*M]; 

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  PII s(-a+c+M, -b+a+M); 
  
  priority_queue<PIII, vector<PIII>, greater<PIII> > Q; 
  Q.push_back(PIII(0, s)); 

  int C[3][6]; 
  REP(i, 3) REP(j, 6) cin >> C[i][j]; 
  
  REP(i, 3) {
    if(C[i][0]>2) {
      C[i][1] += (C[i][0]-1)/2; 
      C[i][0] = 2 - (C[i][0]%2);
    }
  }
  
  return 0; 
}
