#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
#define aINF 12345678912
typedef pair<LLI, LLI> PII;
typedef pair<PII, int> PIIPI; 

/*
4 2 3
0 1 30 N
2 1 30 P
0 1
0 2
0 3
*/

vector<PIIPI> N[4321];

PII route(int from, int to){
  priority_queue<PIIPI, vector<PIIPI>, greater<PIIPI> > Q;
  Q.push(PIIPI(PII(0,0), from)); 
  
  vector<bool> V(4321, false); 
  vector<PII> D(4321, PII(aINF, aINF)); 
  
  while(!Q.empty()){
    PIIPI p = Q.top();
    Q.pop();
    
    if(V[p.second]) continue;
    int v=p.second;
    V[v]=true; 
    PII d=p.first;
    D[v]=d; 
    
    REP(i, N[v].size()){
      Q.push(PIIPI(PII(d.first+N[v][i].first.first, d.second+N[v][i].first.second), N[v][i].second));
    }
  }
  
  return D[to];
}

int main()
{
  int n, m, q;
  cin >> n >> m >> q;

  REP(i, m){
    int a,b,d;
    char p;
    cin >> a >> b >> d >> p;
    PII q = (p=='P')?PII(0,d):PII(d,0);
    N[a].push_back(PIIPI(q,b));
    N[b].push_back(PIIPI(q,a));  
  }
  
  REP(i, q){
    int a,b;
    cin>>a>>b;
    PII r=route(a,b); 
    if(r.first==aINF) cout << "-1 -1" << endl;
    else cout << r.first << " " << r.first + r.second << endl;
  }

	return 0;
}
