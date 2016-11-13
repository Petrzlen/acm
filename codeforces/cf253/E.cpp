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

typedef long long int lli;
typedef pair<int, int> pii; 

#define MAX (1 << 19)
#define INF 1234567890

vector<int> SV(2*MAX, 0); 
vector<int> MA(2*MAX, INF);  

int sbuild(int n){
  if(n < MAX) SV[n] = sbuild(2*n) + sbuild(2*n+1);
  return SV[n]; 
}
int abuild(int n){
  if(n < MAX) MA[n] = min(abuild(2*n), abuild(2*n+1)); 
  return MA[n]; 
}

void supdate(int n, int val){
  if(n <= 0) return; 
  
  SV[n] += val; 
  supdate(n/2, val); 
}
void aupdate(int n, int val){
  if(n <= 0) return; 
  if(n >= MAX) MA[n] = val; 
  else MA[n] = min(MA[2*n], MA[2*n+1]); 
  aupdate(n/2, val); 
}

//<a,b> and <f,t> in <1,n> 
int sget(int a, int b, int n=1, int f=1, int t=MAX){
  //cout << "sget(" << a << "," << b << "," << n << "," << f << "," << t << ")" << endl;

  if(t<a) return 0;
  if(b<f) return 0; 
  if(a<=f && t<=b) return SV[n]; 
  
  return sget(a, b, 2*n, f, (f+t)/2) + sget(a,b,2*n+1, (f+t)/2 + 1, t); 
}

int anext(int n, int val, int last=-1){
  //cout << "anext(" << n << "," << val << "," << last << ")" << endl;

  if(n<=0) return -1;
  if(last == -1 || MA[n] > val) return anext(n/2, val, n); 
  if(n>=MAX && MA[n]<=val) return n-MAX; 
  
  int v = -1; 
  if(last < n) v = anext(2*n, val, n); 
  if(last == 2*n) v = anext(2*n+1, val, n); 
  if(last == 2*n+1) v = anext(n/2, val, n); 
  
  return v; 
}

int main(){
  int N, M;
  cin >> N >> M; 
  
  vector<int> A(N, 0); 
  vector<pii> AS(N, pii(0,0)); 
  REP(i, N) cin >> A[i];
  REP(i, N) AS[i] = pii(A[i], i); 
  sort(AS.begin(), AS.end(), greater<pii>()); 
  
  REP(i, N) SV[MAX+i]=1; 
  sbuild(1); 
  
  vector<int> P(N, 0); 
  REP(a, AS.size()){
    int i = AS[a].second; 
    P[i] = sget(i+2, N); 
    supdate(MAX+i, -1); 
  }
 
  REP(i, N) MA[MAX+i] = A[i]; 
  abuild(1); 
 
  lli sum = 0;
  REP(i, N) sum += P[i]; 
  cout << sum << endl; 
   
  REP(m, M){
    int p;
    cin >> p; 
    p--; 
    int val = A[p]; 
    //cout << p << " val=" << val << endl;
    
    do{
      //cout << "DO " << p << endl;
      sum -= P[p]; 
      P[p]=0; 
      aupdate(MAX+p, INF); 
    }while((p = anext(MAX+p, val)) != -1); 
    
    cout << sum << endl;
  }

  return 0; 
}
