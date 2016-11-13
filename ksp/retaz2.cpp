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
  long long int n;
  long long int result=1; 
  cin >> n;
  cout << (result << (n-1)) << endl;
	return 0;
}
