#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <iomanip> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

#define MAX 1048576
double B[MAX]; 
double J[20];

int cj(int b){
  int result=0;
  while(b>0){
    if(b%2==1) result++;
    b /= 2; 
  }
  return result;
}

int main()
{
  int N;
  cin >> N;
  
  REP(i, MAX) {
    B[i]=0.0;
  }
  B[0]=1.0; 
  
  REP(t, N){
    REP(i, N){
      cin >> J[i]; 
      J[i] /= 100.0; 
    }
    REP(b, MAX){
      if(cj(b)==t+1){
        REP(i, N){
          int bl = b & ((MAX-1) ^ (1 << i));   
          if(cj(bl)==t){
            B[b] = max(B[b], B[bl] * J[i]);
          }
        }
      }
    }
  }
  
  cout << setprecision(9) << B[(1 << N) - 1]*100.0 << endl;
  
	return 0;
}
