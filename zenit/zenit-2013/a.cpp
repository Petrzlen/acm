#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

int main(){
  int sum=0;
  int n; 
  cin >> n;
  REP(i, n){
    int x;
    cin >> x;
    sum += x; 
  }
  if(sum<0) cout << "lavica" << endl;
  if(sum==0) cout << "lavopravostred" << endl;
  if(sum>0) cout << "pravica" << endl;
  
  return 0; 
}
