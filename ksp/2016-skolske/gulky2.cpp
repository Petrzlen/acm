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

vector<int> R(123456, 0); 

int sq(int x){
  int r=1; 
  while(r*r <= x) r++; 
  return r; 
}

int zmotaj(int k, int p, int z, bool b, int m){
  //cout << "k=" << k << " p=" << p << " z=" << z << " b=" << b << endl;

  if(z < 0 || p < 0) return -1; 
  if(k == 0) return z; 
  //if(p != 0 && p % k == 0) return zmotaj(k-1, p+p/k, z, b); 
  
  int d = (k - (p%k)) % k;
  
  if(z < d) return -1; 
  
  for(int a=m ; a>=(p!=0 && p%k==0); a--){
    int p2=p+a+(p+d)/k; 
    int d2=d + a*k; 
    int z2=z - d2; 
    if(a==0 || zmotaj(k-1, p2, z2, false, 1)>=0){
      if(b) R[k] += d2; 
      return zmotaj(k-1, p2, z2, b, 1); 
    }
  }
}

void panko(int n){
  if(n <= 0) return; 
  
  int s=sq(2*n+1)+1; 
  //cout << "sq=" << s << " n=" << n << endl;
  
  while(zmotaj(s, 0, n, false, 3) < 0) s--; 
  panko(zmotaj(s, 0, n, true, 3)); 
}

int main(){
  int n; 
  cin >> n; 
  panko(n); 
  
  REP(i, n) if(R[i+1] != 0) cout << i+1 << " " << R[i+1] << endl;
  
  return 0; 
}
