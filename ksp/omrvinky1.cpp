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
  int n, m;
  cin >> n >> m;
  int result = 0; 
  REP(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    result += c;
  }
    cout << result << endl;
	return 0;
}
