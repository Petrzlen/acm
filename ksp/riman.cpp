#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int solve(int x){
  if(x <= 3) return x;
  if(x == 4) return 3;
  if(x == 5) return 2;
  if(x <= 8) return 2 + solve(x-5); 
  if(x == 9) return 3;
  if(x <= 39) return 2*(x / 10) + solve(x % 10);
  if(x <= 49) return 4 + solve(x % 10); 
  if(x == 50) return 2; 
  if(x <= 89) return 2 + solve(x % 50); 
  if(x <= 99) return 2 + 3 + solve(x % 90); 
  if(x < 400) return 3*(x / 100) + solve(x % 100); 
  if(x < 500) return 3 + 3 + solve(x % 100);
  if(x == 500) return 3;
  if(x < 900) return 3 + solve(x - 500); 
  if(x < 1000) return 7 + solve(x - 900);
  if(x < 2000) return 4 + solve(x - 1000);
  return 8; 
}

int main()
{
  int t;
  cin >> t;
  REP(i, t) {
    int x;
    cin >> x; 
    cout << solve(x) << endl;
  }
	return 0;
}
