#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int K[2][1234567];
  
int main()
{
  int n, k;
  REP(i,2) REP(j, 1234567) K[i][j]=0; 
  vector<pair<int, int> > S; 
  
  cin >> n >> k;
  REP(i, n){
    int x;
    cin >> x;
    bool b = x%2; 
    K[!b][i%k]++; 
  }
  
  REP(i, 2) REP(j, k){
    S.push_back(pair<int, int>(K[i][j], i));
  }
  sort(S.begin(), S.end());
  
  int result = 0;
  int sum = 0;
  REP(i, k) {
    result += S[i].first;
    sum += S[i].second; 
    
    //cout << S[i].first << ":" << S[i].second << endl;
  }
  
  if(sum%2==1){
    result += S[k].first - S[k-1].first;
  }
  cout << result << endl;
  
	return 0;
}
