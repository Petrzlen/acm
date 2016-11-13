#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

#define M 10000000
bool P[M];
set<int> S; 

int rev(int x){
  int result=0;
  while(x>0){
    result *= 10;
    result += x % 10;
    x /= 10; 
  }
  return result;
}

void erast(){
  REP(i, M) P[i]=1;
  P[0]=P[1]=0;
  REP(i, M) {
    if(P[i]==0) continue;
    for(int j=2*i; j<M; j += i) P[j]=0; 
  }
}

void emirp(){
  REP(i,M){
    int r = rev(i);
    if(r == i) continue;
    if(P[i] && P[r]) S.insert(i); 
  }
}

int main()
{
  erast();
  emirp(); 
  S.insert(10000169); 
  int t;
  cin >> t;
  REP(i, t){
    int x;
    cin >> x;
    cout << *(S.upper_bound(x)) << endl;
  }

	return 0;
}
