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
typedef pair<PII, PII> PPP; 

char M[128][128];
bool V[128][128][24]; 
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};  

int main(){
  REP(i, 128) REP(j, 128) M[i][j] = '#'; 
  REP(i, 128) REP(j, 128) REP(k, 24) V[i][j][k] = false; 
  
  int R, C; 
  int sr, sc; 
  cin >> R >> C; 
  REP(r, R){
    string s;
    cin >> s;
    REP(c, C) {
      M[r+1][c+1] = s[c]; 
      if(s[c]=='X'){
        sr = r+1; 
        sc = c+1; 
      }
    }
  }
  
  int result = -1; 
  
  //distance without immunity (before here), -imunity remainig (here), r, c
  priority_queue<PPP, vector<PPP>, greater<PPP> > Q;
  Q.push(PPP(PII(0,0), PII(sr, sc))); 
  while(!Q.empty()){
    PPP ppp = Q.top(); 
    Q.pop(); 
    
    int d=ppp.first.first;
    int im=-ppp.first.second;
    int r=ppp.second.first;
    int c=ppp.second.second; 
    
    //cout << "[" << r << "," << c << "]" << " d=" << d << " im=" << im << endl;
    
    if(V[r][c][im]) continue;
    V[r][c][im] = true; 
    
    if(M[r][c]=='#') continue; 
    if(M[r][c]=='Y') {
      result = d;
      break; 
    }
    
    if(M[r][c]>='1' && M[r][c]<='9') {
      im = max(im, (int)(1 + M[r][c] - '0')); 
      //cout << "im= " << im << endl;
    }
    if(M[r][c]>='A' && M[r][c]<='F') {
      im = max(im, (int)(11 + M[r][c] - 'A')); 
      //cout << "im= " << im << endl;
    } 
    if(M[r][c]=='.' && im == 0) d++; 
    
    REP(i, 4) Q.push(PPP(PII(d, -max(0,im-1)),PII(r+dx[i], c+dy[i]))); 
  }
  
  cout << result << endl;
  
  
  return 0; 
}
