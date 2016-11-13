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
  int k;
  cin >> k;
  int a, b;
  cin >> a >> b;
  for(int n=2; n<=k; n++){
    int x, y;
    cin >> x >> y;

    bool bad = false;
    if(a==b && x==y) bad = true;    
    if(a<b && x>a) bad = true;
    if(a<b && y<b) bad = true; 
    if(a==x && y==b) bad = true; 
    
    if(bad) {
      cout << "interval "<<n<<" to pokazil" <<endl; 
      return 0;
    }
    a=x;
    b=y;
  }
  cout << "retaz radu " << ((a==b)?0:b) << endl; 
  
	return 0;
}
