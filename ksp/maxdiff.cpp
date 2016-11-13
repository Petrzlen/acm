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

LLI zmotaj(string s){
  LLI res = 0; 
  REP(i, s.size()) {res *= 10; res += s[s.size()-1-i];} 
  return res; 
}

int main(){
  LLI n; 
  cin >> n; 
  if(n == 1) {cout << "0" << endl; return 0;}
  if(n == 2) {cout << "72" << endl; return 0;}
  
  string pan(n, '0'); 
  string plac(n, '0'); 
  
  plac[n-1] = '1'; 
  REP(i, n/2) pan[n-1-i] = '9'; 
  if(n%2==1) pan[n/2] = '1'; 
  REP(i, n/2) plac[i] = '9'; 
  if(n%2==0) plac[n/2 - 1] = '8'; 
  
  //cout << pan << endl << plac << endl;
  cout << zmotaj(pan) - zmotaj(plac) << endl;
  
  return 0; 
}
