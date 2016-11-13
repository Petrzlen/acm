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
  int N;
  cin >> N;
  vector<int> B(N, 0);
  REP(i, N) cin >> B[i];
  sort(B.begin(), B.end()); 
   
  priority_queue<int, vector<int>, greater<int> > S;
  S.push(1); 
  
  for(int b=1; b<B.size() ; b++){
    if(B[b] >= S.top()) {
      int s = S.top();
      S.pop(); 
      S.push(s+1); 
    }
    else{
      S.push(1); 
    }
  }
  
  cout << S.size() << endl;
  
  return 0; 
}
