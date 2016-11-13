#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef unsigned long long int ULLI; 

int main()
{
  ULLI n;
  cin >> n;
  if(n < 8) {
    if(n==1) cout << 1 << endl;
    if(n==2) cout << 2 << endl;
    if(n==3) cout << 6 << endl;
    if(n==4) cout << 12 << endl;
    if(n==5) cout << 60 << endl;
    if(n==6) cout << 60 << endl;
    if(n==7) cout << 210 << endl;
  }
  else{
    if(n%2==1) cout << (n-2)*(n-1)*n << endl;
    else if(n%3!=0) cout << (n-3)*(n-1)*n << endl; 
    else { //mod 6
      ULLI P[12] = {5,7,11,13,17,19,23,29,31,37,41,43};
      REP(i, 12){
        if((n-1)*(n-2)*(n-3) >= (n-P[i])*(n-1)*n){
          cout << (n-1)*(n-2)*(n-3) << endl;
          break;
        }
        if(n % P[i] != 0) {
          cout << (n-P[i])*(n-1)*n << endl;
          break;
        }
      }
    }
  }
	return 0;
}
