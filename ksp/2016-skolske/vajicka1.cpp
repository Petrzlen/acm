#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  string s;
  cin >> s;
  s += "#"; 
  int count = 0;   
  REP(i, s.size()){
    if(s[i]=='(') {
      if(s[i+1]==')'){
        count++;
        i++;
      }
      else{
        count = -100000000; 
      }
    }
  } 
  
  cout << ((count>=0)?count:-1) << endl;
  
	return 0;
}
