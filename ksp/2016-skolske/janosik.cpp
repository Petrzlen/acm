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

int main(){
  LLI N;
  cin >> N; 
  
  LLI result = 0; 
  for(LLI i=1; i<(1<<30) ; i*=2){
    LLI j = i*2;
    if(N < i) continue; 
    LLI n = (N >= j) ? i-1 : N-i; 
    
    //cout << i << "," << j << ":" << n << endl;
    
    result += (n*(n+1)) / 2; 
  }
  
  cout << result << endl;
  
  return 0; 
}
