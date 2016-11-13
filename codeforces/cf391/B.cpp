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
  vector<int> p(s.size(), 1); 
  
  for(int i=s.size()-1 ; i >= 0 ; i--){
    for(int j=i+1; j<s.size() ; j+=2){
      if(s[j] == s[i]) p[i] = max(p[i], 1 + p[j]); 
    }
  }
  
  int result=0;
  REP(i, p.size()) {
    //cout << s[i] << " " << p[i] << endl;
    result = max(result, p[i]); 
  }
  cout << result << endl; 
    
  return 0; 
}
