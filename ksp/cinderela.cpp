#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

int main()
{
  int S;
  cin >> S;
  REP(rte, S){
    string s;
    cin >> s;
    LLI a=0;
    LLI b=0; 
    LLI os=0; 
    LLI totalos=0;
    REP(i, s.size()) if(s[i]=='o') totalos++; 
    
    REP(i, s.size()){
      if(s[i]=='o') os++;
      else{ //'.'
        a+=os;
        b+=totalos-os; 
      }
    }
    if(a<b) cout << string(s.size()-os, '.') << string(os, 'o') << endl; 
    else cout << string(os, 'o') << string(s.size()-os, '.') << endl;
    
  }
	return 0;
}
