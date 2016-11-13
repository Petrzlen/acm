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
  string s; 
  cin >> s; 
  char last = '\0'; 
  int length = -1;
  int result = 0;  
  s += "#"; 
  REP(i, s.size()){
    if(last != s[i]) {
      result += (length + 1) % 2; 
      length = 1; 
      last = s[i]; 
    }
    else{
      length ++; 
    }
  }
  cout << result << endl;
  
  return 0; 
}
