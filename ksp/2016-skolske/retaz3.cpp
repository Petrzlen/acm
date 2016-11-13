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
  LLI result=1; 
  LLI mod=1000000009; 
  LLI a,b;
  LLI x,y;
  
  int n;
  cin >> n;
  cin >> a >> b;
  REP(i, n-1){
    cin >> x >> y;
    LLI p;
    if(a<b) p = (a-x) + (y-b);
    else p = y-x; 
    result = (result * p) % mod; 
    
    a=x;
    b=y;
  }
  cout << result << endl; 
  
	return 0;
}
