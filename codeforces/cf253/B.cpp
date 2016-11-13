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

LLI in(){
  string s; 
  cin >> s; 
  
  LLI result = 0; 
  REP(i, s.size()){
    if(s[i]=='.') continue; 
    
    result *= 10; 
    result += s[i]-'0'; 
  }
  return result; 
}

//lower bound of square
LLI sq(LLI x, LLI from=0, LLI to = 1<<30){
  if(from + 1 >= to) return from; 
  
  //cout << "[" << from << "," << to << "]" << endl;
  
  LLI m = (from + to) / 2; 
  if(m*m > x) return sq(x, from, m);
  else return sq(x, m, to); 
} 

int main(){
  int m,n,r;
  cin >> m >> n >> r; 
  r *= 10; 
  LLI x = sq(r*r - 100); 
  
  //cout << x << " " << r*r - 100 << endl;
  
  //sentinels not necessary 
  vector<LLI> C(m+1, -123456789);
  REP(i, m) C[i+1] = in();
  C.push_back(123456789); 
  vector<LLI> CB = C;
  sort(CB.begin(), CB.end(), greater<LLI>()); 
  
  LLI result = 0; 
  LLI c = C[1]; 
  REP(t, n){
    LLI a = in(); 
    
    if(c - x <= a && a <= c + x) continue; 
    
    LLI mi = *lower_bound(C.begin(), C.end(), a-x); 
    LLI ma = *lower_bound(CB.begin(), CB.end(), a+x, greater<LLI>());
    LLI nc = (abs(mi-c)<abs(ma-c)) ? mi : ma; 
    
    result += abs(nc - c); 
    c = nc; 
    
    //cout << nc << endl;
    //cout << a << "[" << mi << "," << ma << "]" << endl;
  }
  
  cout << result / 10 << "." << result % 10 << endl;
  
  return 0; 
}
