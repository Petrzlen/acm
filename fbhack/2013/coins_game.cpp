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

int solve(){
  int N, K, C;
  cin >> N >> K >> C;
  
  int result = 1234567890; 
  for(int n=1; n<=N; n++){
    if(n>K) break;
    int s=K/n; 
    int m=K%n; 
    
    int t = N-n + C + ((C>s*n)?n-s:0);
    result = min(result, t); 
    
    //cout << n << ":" << t << endl;
  }
  return result; 
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }
  return 0; 
}
