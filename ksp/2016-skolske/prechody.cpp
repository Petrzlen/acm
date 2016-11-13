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
typedef unsigned long long int ui64; 

bool in_pair(LLI t, PII p){
  return (p.first <= t && t <= p.second); 
}

void tr(LLI t, LLI m, LLI& besttime){
  if(t >= m) besttime = min(besttime, t); 
}

int main(){
  LLI tz, tc, d; 
  cin >> tz >> tc >> d; 
  tz *= 1000; 
  tc *= 1000; 
  
  LLI m = d; 
  
  vector<PII> A; 
  for(LLI a=0; a <= 1000000 ; a += (tz + tc)){
    A.push_back(PII(a, a + tz));
  }
  
  bool topspeed = false; 
  LLI besttime = 123456789123456789; 
  
  REP(i, A.size()) REP(j, A.size()){
    //speed 1000 
    if(in_pair(A[i].first + m, A[j])) topspeed = true; 
    if(in_pair(A[i].second + m, A[j])) topspeed = true; 
    if(in_pair(A[j].first - m, A[i])) topspeed = true;  
    if(in_pair(A[j].second - m, A[i])) topspeed = true; 
    
    tr(A[j].first - A[i].first, m, besttime); 
    tr(A[j].second - A[i].first, m, besttime); 
    tr(A[j].first - A[i].second, m, besttime); 
    tr(A[j].second - A[i].second, m, besttime); 
  }
  
  if(topspeed) cout << "1000.0000000000" << endl;
  else{
    ui64 ldt = besttime / 1000; 
    ui64 ldd = d; 
    ui64 mod = 1000000000000; 
    ldd *= mod; 
    ui64 res = ldd / ldt; 
    
    string s(12, '0');
    ui64 m = res % mod; 
    REP(i, 12) {
      s[11-i] = ((m % 10) + '0'); 
      m /= 10; 
    }
    cout << (res / mod) << "." << s << endl;
  }
  
  return 0; 
}
