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

LLI K, X, N, M; 

string gen(int length, int c, char b, char e){
  string result(length, e); 
  result[0] = b;
  result[c-1] = e; 
  
  for(int s=(b=='C') ; s<length ; s+=2){
    if(c <= 0) break; 
    
    result[s]='A';
    if(s+1<length) result[s+1]='C';
    c--;
  }
  
  //cout << "gen("<<length << ",c=" << c  << ",b=" << b  << ",e=" << e << ")" << endl;
  
  return result; 
}

bool check(LLI ca, LLI cb, char ba, char ea, char bb, char eb){
  vector<LLI> S(K+1, 0); 
  S[1] = ca;
  S[2] = cb; 
  
  char oba = ba;
  char oea = ea;
  char obb = bb;
  char oeb = eb;
  
  for(int i=3; i<=K ; i++){  
    char bn = ba;
    char en = eb;
    
    S[i] = S[i-2] + S[i-1] + (ea == 'A' && bb == 'C'); 
    ba = bb; 
    ea = eb;
    bb = bn;
    eb = en; 
    
    if(S[i] > X) return false;
  }
  
  if(S[K] == X){
    cout << gen(N, ca, oba, oea) << endl;
    cout << gen(M, cb, obb, oeb) << endl;
    return true; 
  }
  return false;
}

string P[4] = {"AA", "AC", "CA", "CC"}; 
int C[4] = {1, 0, 2, 1}; 
int m[4] = {0, 1, 0, 0}; 

int main(){
  cin >> K >> X >> N >> M; 
  
  LLI one = 1; 
  
  REP(i, 4) REP(j, 4) 
    for(int ca=m[i]; ca <= (N-C[i])/2 ; ca++)
      for(int cb=m[j]; cb <= (M-C[j])/2 ; cb++){
    if(check(ca,cb,P[i][0], P[i][min(one,N-1)], P[j][0], P[j][min(one,M-1)])){
      //cout << "ca=" << ca << " cb=" << cb << " " << P[i][0] << P[i][min(one,N-1)] << " " << P[j][0] << P[j][min(one,M-1)] << endl;
      return 0; 
    }    
  }
  
  cout << "Happy new year!" << endl;
  
  return 0; 
}
