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
  int m;
  int a, b;
  int x;
  int moze_max=-1;
  int moze_ret=-1; 
  
  cin >> m;
  cin >> x;
  a=x;
  b=x; //!uzavrete intervaly
  if(b>m-1) moze_max=1; 
  
  for(int i=2; i<=m; i++){
    cin>>x;
    if(moze_ret < 0 && (x>=a&&x<=b)) moze_ret = i;
    if(moze_max < 0 && !(x==a-1||x==b+1)) moze_max = i;
    a=min(a,x);
    b=max(b,x); 
    if(moze_max < 0 && b>m-1) moze_max = i; 
  }
  if(moze_ret > 0) cout << "nie " << moze_ret << endl;
  else if(moze_max > 0) cout << "ano " << moze_max << endl;
  else cout << "ano, maximalna radu " << m << endl;
  
	return 0;
}
