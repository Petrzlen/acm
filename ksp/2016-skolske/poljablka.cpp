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

set<int> R;
bool V[2048][1024];

void solve(int j, int z){
  if(j<0 || z<0) return; 

  if(V[j][z]) return;
  V[j][z] = true; 

  if(z==0 || j==0) {
    R.insert(j); 
    return; 
  }
  
  if(j <= 0) return; 
  
  if(j % 2 == 0) solve(j/2, z-1); //chlapec
  solve(j-1, z-1);  //dievca
}

int main(){
  REP(i, 2048) REP(j, 1024) V[i][j] = false; 

  int J, Z; 
  cin >> J >> Z;
  J *= 2; 
  
  solve(J, Z); 
  
  cout << R.size() << endl; 
  bool first = true; 
  for(set<int>::iterator iter = R.begin() ; iter != R.end() ; iter++){
    if(!first) cout << " "; 
    first = false; 
    
    int x = *iter; 
    cout << x/2 << "." << ((x % 2==0)?'0':'5'); 
  }
  cout << endl;
  
  return 0; 
}
