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
typedef pair<LLI, LLI> PII;
LLI INF = 123456789123456789ll; 

bool cmp(PII p1, PII p2){
  return (p1.second - p1.first < p2.second - p2.first); 
}

int main(){
 int N, K;
 cin >> N >> K;
 
 vector<LLI> V(N, 0); 
 REP(i, N) cin >> V[i]; 
 
 // buy (want to sell) k, price, profit_before  
 vector<PII> B(K+1, PII(INF, 0)); 
 // sell k, profit_total  
 vector<LLI> S(K+1, 0); 
 
 REP(i, N) {
   // buy 
   REP(k, S.size()) {
     if(k < K) {
       PII b(V[i], S[k]); 
       if(cmp(B[k+1], b)) B[k+1] = b;
     }
   }
   // sell 
   REP(k, B.size()) {  
     LLI p = V[i] - B[k].first; 
     if(p <= 0) continue; 
     
     //cout << k << ":" << B[j].second.second << "+(" << B[j].second.first << " -> " << V[i] << ")" << endl;
     S[k] = max(S[k], B[k].second + p); 
   }
 }
 
 LLI result = 0;
 REP(i, S.size()) {
   result = max(result, S[i]); 
 }
 cout << result << endl;
}
