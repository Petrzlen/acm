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
  string in;
  getline(cin, in); 
  string s; 
  REP(i, in.size()) if(in[i] != ' ') s += in[i]; 
  
  map<char, vector<LLI> > M; 
  REP(i, s.size()) M[s[i]].push_back(i); 
  
  LLI result = 0; 
  
  for(map<char, vector<LLI> >::iterator iter = M.begin() ; iter != M.end() ; iter++){
    vector<LLI> V = iter->second;
    LLI n = V.size(); 
     
    for(LLI i=0; i<n - 1 ; i++){
      result += (i + 1) * (V[i+1] - V[i]) * (n - i - 1); 
      //cout << "i=" << i << " V[i]=" << V[i] << " V[i+1]=" << V[i+1] << " n=" << n << " => " <<  (i + 1) * (V[i+1] - V[i]) * (n - i)  << endl;
    }
    result -= (n * (n-1)) / 2; 
    
    //cout << "  minus:" << (n * (n-1)) / 2 << endl;
  }
  
  cout << result << endl;
  
  return 0; 
}
