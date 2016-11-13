#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

int N; 
int P[1234567];
LLI S[1234567];  
map<string, int> M; 

int preloz(string s){
  if(M.count(s) == 0){
    int i = M.size();
    M[s] = i; 
    P[i] = i;
    S[i] = 1; 
  }
  return M[s];
}

int fi(int a){
  int b = a;
  while(P[b] != b){
    b = P[b];
  }
  while(P[a] != a){
    int c = a;
    a = P[a];
    P[c] = b;  
  }
  return b; 
}

LLI un(int a, int b){
  a = fi(a);
  b = fi(b); 
  if(a != b) {
    LLI result = S[a] * S[b];
    P[a] = b;
    S[b] += S[a];  
    return result;
  }
  return 0; 
}

int main()
{
  cin >> N;
  REP(i, N){
    string s1, s2;
    cin >> s1 >> s2;
    int a = preloz(s1);
    int b = preloz(s2);
    cout << un(a,b) << endl;
  }
  
	return 0;
}
