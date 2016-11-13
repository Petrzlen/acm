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

int main(){
  LLI N;
  cin >> N;
  
  if(N==0) {
    cout << 1 << endl;
    return 0;
  }
  
  LLI x = N;
  LLI y = 0; 
  LLI steps = 1; 
  bool last_move = true; //up = true, left = false 
  LLI minus_result = 0; 
  
  while(!(x==0 && y==N)){
    bool cur_move = true; 
  
    y++; 
    if((x*x + y*y > N*N)) {
      y--;
      x--; 
      cur_move = false; 
    } 
    
    minus_result += (last_move == false && cur_move == true);
    
    last_move = cur_move; 
    steps++;   
  }
      
  cout << 4*(steps - minus_result - 1) << endl;
  
  return 0; 
}
