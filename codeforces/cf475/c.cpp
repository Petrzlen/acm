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

#define INF 987654321 
bool COUT = false; 
int n, m; 
bool P[2000][2000];
bool C[2000][2000]; 

void swa(){
  if(COUT) cout << "swap" << endl;
  swap(n, m); 
  REP(i, 2000) REP(j, 2000) P[i][j] = C[j][i]; 
}

int zmotaj(int x, int y){
  int h=1; int w=1; 
  while(P[x][y+w]) w++; 
  //w is constant 
  
  if(COUT) cout << "zmotaj " << x << "," << y << " w=" << w << endl; 
  if(COUT) REP(i, n) {REP(j,m) cout << ((P[i][j])?'X':'.'); cout << endl;} 
  
  vector<PII> C(1, PII(x,y));
  
  while(true){
    if(!P[x][y]) break; 
    if(COUT) cout << x << "," << y << endl;
    if(P[x][y+w]){ //go right 
      while(P[x+h][y]) h++; 
      y++; 
    }
    else{ //go down 
      x++; 
    }
    C.push_back(PII(x,y)); 
  }
  
  if(COUT) cout << "path("<<C.size()<<") w=" << w << " h=" << h << endl;
  bool s=false; 
  for(int c=C.size()-1; c>=0; c--){
    int a = C[c].first; 
    int b = C[c].second; 
    if(COUT) cout << a << " " << b << endl;
    
    if(s) {
      if(C[c+1].first != C[c].first) {
        REP(j, w) {
          if(!P[a][b+j]) return INF; 
          P[a][b+j]=false; 
        }
      } 
      if(C[c+1].second != C[c].second) {
        REP(i, h) {
          if(!P[a+i][b]) return INF; 
          P[a+i][b] = false; 
        }
      }
    }
    if(!s) if(P[a+h-1][b+w-1]) {
      if(COUT) cout << "start " << a << " " << b << endl;
      s = true; 
      REP(i, h) REP(j, w) {
        if(!P[a+i][b+j]) return INF; 
        P[a+i][b+j] = false; 
      }
    }
  }
  
  REP(i, n) REP(j, m) if(P[i][j]) return INF; 
  return w*h; 
}

int main(){
  REP(i, 2000) REP(j, 2000) C[i][j] = P[i][j] = false; 

  cin >> n >> m; 
  REP(i, n) {string s; cin >> s; REP(j, m) C[i][j] = P[i][j] = (s[j] == 'X');}
  
  int x=INF, y=INF;
  int r=INF; 
  REP(i, n) if(x==INF) REP(j, m) if(P[i][j]) {x=i; y=j; break;} 
  if(x!=INF){
    if(P[x+1][y]) {
      r = zmotaj(x,y); 
      if(COUT) cout << "r=" << r << endl; 
      swa(); 
      r = min(r, zmotaj(y,x)); 
      if(COUT) cout << "r=" << r << endl; 
    }
    else {swa(); r = zmotaj(y, x);
      if(COUT) cout << "r=" << r << endl; } 
  }
  
  cout << ((r==INF || x==INF)?-1:r) << endl;
  
  return 0; 
}
