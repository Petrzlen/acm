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
  priority_queue<PII, vector<PII>, greater<PII> > Q; 
  int N; 
  cin >> N; 
  int a,b; 
  cin >> a >> b; 
  Q.push(PII(0, a+b)); 
  
  bool all = true; 
  int ma = 0; 
  REP(i, N-1){
    cin >> a >> b; 
    while(Q.top().second < a){
      Q.pop(); 
      if(Q.empty()){
        all = false; 
        break; 
      }
    }
    
    ma = max(ma, Q.top().first + 1);  
    Q.push(PII(Q.top().first + 1, a+b)); 
  }
  
  if(!all) cout << "nerozsteka sa cela dedina" << endl;
  else cout << ma << endl;
  
  return 0; 
}
