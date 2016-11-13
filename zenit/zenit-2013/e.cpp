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
  map<string, string> Z; 
  int N, M;
  cin >> N >> M; 
  REP(i, N){
    string s1, s2;
    cin >> s1 >> s2;
    Z[s1] = s2; 
  } 
  
  int K;
  cin >> K;
  string R = Z["Marosko"]; 
  replace(R.begin(), R.end(), 'N', '.'); 
  
  REP(k, K){
    int x;
    cin >> x;
    R[x-1] = 'B'; 
  }
  replace(R.begin(), R.end(), 'A', 'C'); 
    
  for(map<string, string>::iterator iter = Z.begin(); iter != Z.end(); iter++){
    if(iter->first == "Marosko") continue; 
    
    bool ronaldo = true; 
    for(int i=0; i<R.size(); i++){
      if(R[i]=='B' && iter->second[i] != 'A') ronaldo = false; 
      if(R[i]=='C' && iter->second[i] == 'A') ronaldo = false; 
    }
    
    if(ronaldo) {
      cout << iter->first << endl;
      break;
    }
  }
  
  return 0; 
}
