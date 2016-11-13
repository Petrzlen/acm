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
typedef pair<int, LLI> PII; 

//union find s komprimaciou cesty
//P[a] -> (b, w) 
PII P[123456];

int fi(int id){
  int oid=id;
  LLI s=0; 
  while(P[id].first != id) {
    s += P[id].second; 
    id = P[id].first; 
  } 
  while(P[oid].first != oid) {
    int bid=oid;
    oid = P[oid].first; 
    
    P[bid].first = id; 
 
    LLI bw = P[bid].second;
    P[bid].second = s;
    s -= bw; 
  }
  
  return id; 
}

int un(int a, int b, LLI w){
  int ia = fi(a);
  int ib = fi(b); 
  if(ia != ib){
    P[ia].first = ib; 
    P[ia].second = w - P[a].second; 
  }
}

int main()
{
  int d, u; 
  cin >> d >> u; 
  
  REP(i, 123456) P[i] = PII(i, 0); 
  
  REP(t, u){
    char c;
    cin >> c;
    
    if(c=='!'){
      int a,b;
      LLI w;
      cin >> a >> b >> w; 
      un(a,b,w); 
      
      //REP(i, d) cout << P[i+1].first << "," << P[i+1].second << endl;
    }
    
    if(c=='?'){
      int a,b; 
      cin >> a >> b;
      int ia = fi(a); 
      int ib = fi(b); 
      if(ia != ib){
        cout << "UNKNOWN" << endl;
      }
      else{
        cout << P[a].second - P[b].second << endl;
      }
    }
  }
  
  
	return 0;
}
