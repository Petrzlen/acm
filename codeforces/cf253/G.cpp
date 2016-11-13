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
#include <complex> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

int K; 
string S, Sin; 
vector<int> D; 

int parse(int p=0, int d=0){
  cout << S.substr(0,p+1) << ":" << d << endl;

  if(p < 0 || S[p]=='#') return -1; 
  if(S[p]=='(') p = parse(p+1, d); 
  
  if(S[p]==')') return p+1; 
  if(S[p]=='a') p++; 
  
  if(S[p]=='+' || S[p]=='-') p = parse(p+1, d+1); 
  else if(S[p]=='*') p = parse(p+1, d); 
  D[d]++;
  
  parse(p, d); 
}

int main(){
  cin >> K >> Sin;
  Sin += "#####"; 

  REP(p, Sin.size()){
    if(Sin[p]=='#') break; 
    
    while(Sin[p]=='(')  {S += '('; p++;}
    while(Sin[p]=='-') p++; 
    while(('0' <= Sin[p] && Sin[p] <= '9') || ('a' <= Sin[p] && Sin[p] <= 'z')) p++; 
    S += 'a'; 
    while(Sin[p]==')') {S += ')'; p++;}
    if(Sin[p]=='#') break; 
    S += Sin[p];
  }
  
  D = vector<int>(S.size(), 0); 
  S += '#'; 
  parse(); 
  
  return 0; 
}
