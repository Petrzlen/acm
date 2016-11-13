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

int n, m; 
string N, M; 
bool R[21][21]; 
bool V[21][21]; 

bool zmotaj(int x, int y){
  //cout << "zmotaj " << x << "," << y << endl; 

  REP(i, n) REP(j, m) R[i][j] = V[i][j] = false; 
  queue<PII> Q; 
  Q.push(PII(x,y)); 
  
  while(!Q.empty()){
    PII p = Q.front(); 
    Q.pop(); 
    
    if(V[p.first][p.second]) continue; 
    V[p.first][p.second] = true; 
    R[p.first][p.second] = true; 
    
    //cout << p.first << "," << p.second << endl; 
    
    if(N[p.first]=='>') for(int j=p.second+1 ; j<m; j++) Q.push(PII(p.first, j)); 
    if(N[p.first]=='<') for(int j=p.second-1 ; j>=0; j--) Q.push(PII(p.first, j)); 
    if(M[p.second]=='v') for(int i=p.first+1 ; i<n; i++) Q.push(PII(i, p.second)); 
    if(M[p.second]=='^') for(int i=p.first-1 ; i>=0; i--) Q.push(PII(i, p.second)); 
  }
  
  REP(i, n) REP(j, m) if(R[i][j]==false) return false; 
  return true; 
}

int main(){
  cin >> n >> m; 
  
  N = string(n, '.'); 
  M = string(m, '.'); 
  REP(i, n) cin >> N[i];
  REP(i, m) cin >> M[i]; 
  
  bool ok = true; 
  REP(i, n) REP(j, m) ok = ok && zmotaj(i, j); 
  
  cout << ((ok)?"YES":"NO") << endl;
  
  return 0; 
}
