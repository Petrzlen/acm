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
  LLI n, m;
  int h;
  cin >> n >> h;
  m=1;
  REP(i, h) m *= 2; 
  n = (n-1) % m; 
  
  LLI result = 0; 
  REP(i, h){
    result *= 2;
    result += n % 2;
    n /= 2;
  }
  cout << result << endl;
  
	return 0;
}
