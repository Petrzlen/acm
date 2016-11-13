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
  int N, M; 
  cin >> N >> M; 
  
  priority_queue<int, vector<int>, greater<int> > Q;
  REP(i, M) Q.push(0); 
  
  int ma = 0; 
  double op = 1.0; 
  double result = 0.0; 
  REP(i, N){
    int t;
    double p; 
    cin >> t >> p; 
    
    //cout << Q.top() << "(" << Q.size() << ")"<< endl;
    
    int nt = Q.top() + t;
    Q.pop(); 
    
    ma = max(ma, nt);
    Q.push(nt);  
    
    double dp = op*(1-p); 
    result += dp * ((double)ma); 
    op *= p; 
    
    //cout << "mit=" << ma << " op=" << op << " dp=" << dp << endl;
  }
  result += op * ((double)ma); 
  
  printf("%.7lf\n", result); 
  
  return 0; 
}
