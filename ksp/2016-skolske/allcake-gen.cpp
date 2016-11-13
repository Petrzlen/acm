#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <ctime>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;


int main()
{
  int a = rand() % 10000 + 1024;
  int b = rand() % 10000 + 1024;
  int n = rand() % 1000;
  int k = rand() % ((n+1)*(n+1)); 
  
  cout << a << " " << b << " " << n << " " << k << endl;
  
  int last; 
  last = 0;
  REP(i, n) {
    last = last + 1 + (rand() % (a - last - (n-i) - 2)) / (a / 10);
    cout << last << " ";
  }
  cout << endl;
  last = 0;
  REP(i, n) {
    last = last + 1 + (rand() % (b - last - (n-i) - 2)) /  (b / 10);
    cout << last << " ";
  }
  cout << endl;
  
	return 0;
}
