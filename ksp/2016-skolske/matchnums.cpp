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
typedef pair<LLI, LLI> PII; 

int P[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 

LLI R[11] = {
0,
6,
81,
737,
9711,
91511,
974111,
9711177,
97171711,
777111111,
9741111111
};

LLI H[8] = {
97171711111,
977111111711,
9714111111111,
95711711111111,
971111171111114,
9771171111111111, 
97771117111711111,//97711711141111111, //4,5,9
977111711111111111 //941111111111711111
};

LLI zmotaj(LLI x){
  int r=0; 
  while(x > 0) {
    r += P[x%10]; 
    x /= 10; 
  }
  return r; 
}

inline LLI zmen(const LLI& c, const int& f, const int& x, const LLI& t){
  return (c + (t * (x - (f ? 1 : 7))));  
}

//priority_queue<PII> V; 
PII B(0, 0);   
  
LLI pohaluz(int d){
  REP(b, (1 << d)) {
    LLI c=0;
    LLI T=1; 
    REP(i, d) {
      c *= 10; 
      T *= 10; 
      c += (b & (1<<i)) ? 1 : 7; 
    }
    T /= 10; 
    LLI zc = zmotaj(c); 
    
    int Isize = 3; 
    int Iter[3] = {4,9,1};  
    
    LLI ti=T; 
    
    REP(i, d) {
      LLI tj=T; 
      REP(j, d) {
        if(i!=j) REP(ix, Isize) REP(iy, Isize) {
          int x=Iter[ix]; 
          int y=Iter[iy]; 
        
          LLI c2 = zmen(c, b&(1<<i), x, ti); 
          LLI c3 = zmen(c2, b&(1<<j), y, tj); 
          
          LLI z = zmotaj(c3); 
          //LLI z = zc - P[(b&(1<<i)?1:7)] - P[(b&(1<<j)?1:7] + P[x] + P[y];  
          
          //cout << c << " " << i << "-" << x << " " << j << "-" << y << " " << c3 << " " << z << endl;
          
          //if((c3 % z) == 0) V.push(PII(-c3/z, -c3)); 
          //if(V.size() > 20) V.pop(); 
          if(c3 % z == 0){
            PII C(c3/z, c3); 
            if(C > B) B = C; 
          }
        }
        tj /= 10; 
      }
      ti /= 10; 
    }
  }
}

int main(){
  int k; 
  cin >> k; 
  for(int d=1; d<=min(k,10); d++) cout << R[d] << endl;
  for(int d=11; d<=min(k, 18); d++) cout << H[d-11] << endl;
  return 0; 
  
  for(int i=18; i<=18; i++){
    B=PII(0, 0); 
    pohaluz(i);
    cout << B.first << " " << B.second << endl; 
  }
  
  /*
  for(LLI i=1; i<=n; i++) {
    LLI z = zmotaj(i); 
    if((i % z) == 0) V.push(PII(-i/z, i)); 
    if(V.size() > 20) V.pop(); 
  }
  */ 
  /*
  cout << " done " << endl;
  while(!V.empty()) {
    PII p = V.top(); 
    V.pop(); 
    cout << -p.first << " " << -p.second << " " << p.second / p.first << endl;
  } */ 
  
  return 0; 
}
