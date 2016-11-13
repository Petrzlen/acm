#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define MAXV 5000

int main()
{
  vector<long long int> P(MAXV*2+1,-1); 
  int n, v;
  cin >> n >> v;
  
  P[0]=0;
  REP(t, n){
    int w, l; 
    cin >> l >> w; //weight & length
    if(l > v) l = v; 
    for(int p=v; p>=0; p--){
      if(P[p]==-1) continue;
      if(P[p+l]==-1 || P[p+l]>P[p]+w) {
        //cout << P[p] << " " << P[p + l] << " " << l << " " << w << endl;
        P[p+l]=P[p]+w;
      }
    }
  }
  long long int result = 123456789123456; 
  for(int i=v; i<=v*2; i++){
    if(P[i]==-1) continue;
    result = min(result, P[i]);
  }
  //REP(i, 2*v+1){
  //  cout << "P["<<i<<"]="<<P[i]<<endl;
  //}
  
  cout << result + v << endl;
  
	return 0;
}
