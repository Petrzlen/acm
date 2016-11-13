#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define INF 123456789123456

typedef long long int LLI; 
typedef pair<LLI, LLI> PII;

PII roz(LLI r, LLI a){
  if(r % a == 0) return PII(r/a, r/a);
  else return PII(r/a, r/a + 1); 
}

LLI solve(LLI a, LLI b, LLI r, LLI c){
  PII p = roz(r,a);
  PII q = roz(c,b);
  if(p.first == 0 || q.first == 0) return INF; 
  return p.second * q.second - p.first * q.first; 
}

int main()
{
  LLI r, c, n;
  cin >> r >> c;
  cin >> n;
  n++;
  
  LLI B = INF;
  for(int i=1; i<=n;i++){
    if(n % i == 0)
      B = min(B, solve(i, n/i, r, c));
  }
  
  cout << ((B==INF)?-1:B) << endl;

	return 0;
}
