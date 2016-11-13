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
  vector<bool> P(256, false); 

  int N;
  cin >> N; 
  
  REP(i, N) {
    string s;
    cin >> s; 
    P[s[0]]=true; 
    
    cout << s << endl; 
  }
  
  int result = 0;
  for(int i='A'; P[i] && i<= 'Z' ; i++, result++); 
  cout << result;
  
  return 0; 
}
