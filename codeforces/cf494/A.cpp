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
  int sum = 0; 
  
  vector<int> result; 
  REP(i, s.size()) {
    if(s[i] == '(') sum++;
    if(s[i] == ')' || s[i] == '#') sum--;
    if(s[i] == '#') result.push_back(1); 
  }
  if (sum < 0) {
    cout << -1 << endl;
    return 0;
  }
  
  result[result.size()-1] += sum;
  
  sum = 0;
  int hi=0;
  REP(i, s.size()) {
    if(s[i] == '(') sum++;
    if(s[i] == ')') sum--;
    if(s[i] == '#') sum -= result[hi++];
    if(sum < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  REP(i, result.size()) {
    if(i!=0) cout << " ";
    cout << result[i];
  }
  cout << endl;
  
  return 0; 
}
