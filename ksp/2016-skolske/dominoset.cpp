#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef pair<int, int> PII; 

int main()
{
  int m;
  cin >> m;
  
  set<PII> S; 
  vector<pair<int, PII> > Q; 
  int x=0; 
  
  REP(i, m){
    int a,b;
    cin >> a >> b;
    S.insert(PII(min(a,b),max(a,b))); 
    x = max(x, max(a,b)); 
  }
  
  int n=0;
  for(n=0; n<1234; n++){
    bool missing=false; 
    for(int a=0; a<=n; a++){
      if(S.find(PII(a,n)) == S.end()){
        missing=true; 
      }  
    }
    if(missing) break; 
  } 
  
  n = max(n, x); 
  
  REP(i, n+1) REP(j, i+1) Q.push_back(pair<int, PII>(i+j, PII(j, i))); 
  sort(Q.begin(), Q.end()); 
 
  REP(i, Q.size()){
    //cout << Q[i].first << ": " << Q[i].second.first << Q[i].second.second << endl;
    PII d = Q[i].second; 
    if(S.find(d) == S.end()){
      cout << max(n, x) << endl << d.first << " " << d.second << endl;
      break; 
    }
  }
  
	return 0;
}
