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
#include <complex> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

//ch, co, hu, ta, dr, empty
int m(int i, int j, int k, int t, int d, int r) {
  return i + 21*(j + 21*(k + 21*(t + 21*(d)))); 
}

map<int, double> P; 
map<int, double> E;  

int main(){
  int N;
  cin >> N;  
  
  E[m(0,0,0,0,0,0)] = 1.0; 
  for(int r = 1; r <= N ; r++)  REP(i, 21) REP(j, 21) REP(k, 21) REP(t, 21) REP(d, 21) if(i + j+ k + t + d == r){
    E[m(i,j,k,t,d,r)] = 
      ((double)1.0)/((double)6.0) * E[m(i-1,j,k,t,d,r-1)]
      + 
      ((double)1.0)/((double)6.0) * E[m(i,j-1,k,t,d,r-1)]
      + 
      ((double)1.0)/((double)6.0) * E[m(i,j,k-1,t,d,r-1)]
      + 
      ((double)1.0)/((double)6.0) * E[m(i,j,k,t-1,d,r-1)]
      + 
      ((double)2.0)/((double)6.0) * E[m(i,j,k,t,d-1,r-1)];
      
    //cout << "E:" << i << "," << j << "," << k << "," << t << "," << d << ";" << r << "=" << E[m(i,j,k,t,d,r)] << endl; 
  } 

  REP(i, 21) REP(j, 21) REP(k, 21) REP(t, 21) REP(d, 21) REP(r, 21) if(i + j + k + t + d + r == N){
    double b=0; 
    if(t <= d){
      b = (i > 0 && j > 0 && k > 0)*3 + i + j + k; 
    }
    P[m(i,j,k,t,d,r)] = b; 
    
    //cout << i << "," << j << "," << k << "," << t << "," << d << ";" << r << "=" << b << endl; 
  }
  
  for(int r = 1; r <= N ; r++) 
    for(int i = N-r ; i >= 0 ; i--) 
      for(int j = N-r-i ; j >= 0; j--)
        for(int k = N-r-i-j ; k >= 0 ; k--) 
          for(int t = N-r-i-j-k ; t >= 0 ; t--) {      
    int d = N-r-i-j-k-t;        
    double b = 0.0; 
    LLI c = 0; 
    
    for(int i2 = r ; i2 >= 0 ; i2--) 
      for(int j2 = r-i2 ; j2 >= 0; j2--)
        for(int k2 = r-i2-j2 ; k2 >= 0 ; k2--) 
          for(int t2 = r-i2-j2-k2 ; t2 >= 0 ; t2--){
      int d2 = r-i2-j2-k2-t2; 
      
      //double bb = P[m(i+i2,j+j2,k+k2,t+t2,d+d2,0)]; //keep all, i.e. end
      double bi = (i2 == 0 || i > 0) ? 0.0 : P[m(i+i2,j,k,t+t2,d,j2+k2+d2)];
      double bj = (j2 == 0 || j > 0) ? 0.0 : P[m(i,j+j2,k,t+t2,d,i2+k2+d2)];
      double bk = (k2 == 0 || k > 0) ? 0.0 : P[m(i,j,k+k2,t+t2,d,i2+j2+d2)];
      double bd = (d2 == 0) ? 0.0 : P[m(i,j,k,t+t2,d+d2,i2+j2+k2)];
      
      double b2 = max(bi, max(bj, max(bk, bd))); 
      //double b2 = max(bb, max(bi, max(bj, max(bk, bd)))); 
      
      //not able to set aside 
      if((i2==0||i>0)&&(j2==0||j>0)&&(k2==0||k>0)&&(d2==0)) {
        b2 = P[m(i,j,k,t+t2,d,i2+j2+k2+d2)];
        //cout << "  cannot " << i << "," << j << "," << k << "," << t+t2 << "," << d << ";" << i2+j2+k2+d2 << endl;
      }
      
      b += E[m(i2,j2,k2,t2,d2,r)] * b2; 
      c++; 
      
      //cout << "  " << i2 << "," << j2 << "," << k2 << "," << t2 << "," << d2 << ";" << "=" << b2 << ":" << round(E[m(i2,j2,k2,t2,d2,r)]*36) << endl; 
    }
    
    //cout << "old=" << P[m(i,j,k,t,d,r)] << " new=" << b << endl;
    P[m(i,j,k,t,d,r)] = max(b, P[m(i,j,k,t,d,r)]); 
    
    //cout << i << "," << j << "," << k << "," << t << "," << d << ";" << r << "=" << b  << endl; 
  }
  
  cout << setprecision(15) << P[m(0,0,0,0,0,N)] << endl;
  
  return 0; 
}
