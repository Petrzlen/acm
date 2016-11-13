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

typedef unsigned long long int UL;
typedef pair<UL, UL> PUL; 

#define M 25 
UL L =((((UL)(1 << 31)) * ((UL)(1 << 31)) * 2) - 1) * 2; 
vector<PUL> C; 
UL P[M] = {
2,3,5,7,11,
13,17,19,23,29,
31,37,41,43,47,
53,59,61,67,71,
73,79,83,89,97}; 

void F(UL a, UL pa, int i, int mi){
  int j = 0; 
  while(a<L && j<=mi){
    C.push_back(PUL(a, pa * (j+1))); 
    
    if(L / (P[i] + 1) < a) {
      break;
    }
    
    a *= P[i]; 
    j++; 
    
    F(a, pa * (j+1), i+1, j);
  }
} 

vector<UL> pankovia; 

void init(){
  F(1, 1, 0, 60); 
  sort(C.begin(), C.end()); 
  
  UL pmax = 0; 
  REP(i, C.size()){
    if(C[i].second > pmax){
      pmax = C[i].second; 
      pankovia.push_back(C[i].first); 
      //cout << C[i].first << ":" << C[i].second << endl;
    }
  }
}

int main()
{
  init(); 
  
  UL n;
  cin >> n; 
  
  REP(i, pankovia.size()) if(pankovia[i] > n){
    cout << pankovia[i] << endl;
    break;
  }
  
	return 0;
}
