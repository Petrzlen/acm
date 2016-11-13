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

//from, to, depth
LLI P[100][100];

int main()
{
  REP(i,100) REP(j, 100) P[i][j]=0; 

  string s;
  cin >> s; 
  P[0][0]=1;
  REP(i, s.size()) {
    if(s[i]=='(' || s[i]=='?') REP(d, 99) P[i+1][d+1] += P[i][d];
    if(s[i]==')' || s[i]=='?') REP(d, 99) P[i+1][d] += P[i][d+1];
  }
  cout << P[s.size()][0] << endl;
  
	return 0;
}
