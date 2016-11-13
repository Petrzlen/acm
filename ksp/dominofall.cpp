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
#define S 1048576
PII T[2*S];
int D[S];
int J[S];
bool P[S];

PII get(int ta, int tb, int id=1, int a=0, int b=S){
  if(a+1 >= b) return T[S+a];
  if(ta==a && tb == b) return T[id];
  
//  cout << ta << "," << tb << "," << id << "," << a << "," << b << endl;
  
  int m=(a+b)/2;
  
  if(tb <= m) return get(ta, tb, id*2, a, m); 
  if(ta >= m) return get(ta, tb, id*2+1, m, b); 
  
  return max(
    get(ta, m, id*2, a, m),
    get(m, tb, id*2+1, m, b)
  );
} 

void jump(int a, int b){
  if(a+1 >= b) return; 
  PII t=get(a,b); 
  P[t.second]=true; 
  bool left=false;
  bool right=false; 
  if(t.second > a) {
    J[get(a,t.second).second] = t.second;
    jump(a, t.second); 
    left=true;
  }
  if(t.second < b-1) {
    J[get(t.second+1, b).second] = t.second;  
    jump(t.second+1, b);   
    right=true;
  }
  if(left && right) D[t.second]=S; 
}

int depth(int id){
  if(J[id] < 0) {
    if(D[id]<0) D[id]=1;
    return 1;
  }
  int d=depth(J[id]); 
  if(D[id]<0) D[id]=d+1;
  return d+1;
}

int main()
{
  REP(i, 2*S) T[i] = PII(-1, -1);
  REP(i, S) D[i]=J[i]=-1; 
  REP(i, S) P[i]=false; 
  
  int n;
  cin >> n;
  REP(i, n){
    int x;
    cin >> x;
    T[S+i] = PII(x, i);
  }

  for(int i=S-1; i>=1; i--) T[i] = max(T[2*i], T[2*i + 1]); 
 
  jump(0, n);  

  REP(i, n) if(!P[i]) depth(i); 
 // REP(i, n) cout << J[i] << endl;
 // cout << endl;
 // REP(i, n) cout << D[i] << endl;

  int result = n; 
  REP(i, n) result = min(result, D[i]); 
  
  cout << result << endl;

	return 0;
}
