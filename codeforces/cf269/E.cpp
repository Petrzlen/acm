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
  LLI A=0;
  LLI B=0; 
  int N;
  string S;
  cin >> N >> S; 

  LLI result = 0; 
  REP(i, S.size()){
    if(S[i]=='2') {
      if(A + 2*B + 2 <= N) B++;
    }
    else {
      if(A + 2*B + 1 <= N) A++; 
      else if(B>0){
        B--;
        A++; 
      }
    }
    
    result += A+B; 
    //cout << S[i] << ": " << A << ":" << B << endl;
  }
  cout << result << endl;

  return 0; 
}
