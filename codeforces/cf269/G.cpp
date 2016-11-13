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

LLI ma(LLI A, LLI a){
  A -= a; 
  return 1 + A / (2*a + 1); 
}

int main(){
  LLI W, H, w, h;
  cin >> W >> H >> w >> h; 
  
  cout << ma(W,w) * ma(H, h) << endl;
  
  return 0; 
}
