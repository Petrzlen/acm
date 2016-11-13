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

class Trie{
  public: 
    Trie() : c(0) {
      REP(i, 26) n[i] = NULL; 
    }
  
    void add(const string& s, int pos){
      if(pos >= s.size()){
        return; 
      }
      
      int si = s[pos] - 'a'; 
      if(n[si]==NULL){
        n[si] = new Trie(); 
      }
      
      c++; 
    }
   
    int c;
    Trie* n[26]; 
}; 

int main(){
  int N; 
  Trie T; 
  cin >> N;   
  
  REP(t, N){
    string s; 
    cin >> s;
    reverse(s.begin(), s.end()); 
    T.add(s, 0); 
  }
  
  return 0; 
}
