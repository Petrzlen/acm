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

int P[12345]; 

int main(){
  REP(i, 12345) P[i] = -1; 
  
  LLI a, b, x, M;
  cin >> a >> b >> x >> M;
  LLI origa = a % M;
  a = 1;  
  
  if(b==0) a=1; 
  for(int i=0; 0<b && a>0 ; i++, b--, a = (a*origa) % M){
    if(P[a] >= 0) b = b % (i - P[a]);
    else P[a] = i;  
  }
  
  //REP(i, M) cout << i << ":" << P[i] << endl;
  
  if(a==x) cout << "rovne" << endl;
  if(a<x) cout << "menej" << endl;
  if(a>x) cout << "viac" << endl;
  
  return 0; 
}
