#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

using namespace std;

LLI A[212345];
LLI B[212345];
int R[212345];

int N;
LLI K; 
LLI x, y; 
LLI maxLLI = 123456789123456789ll;

int main()
{
  cin >> x >> y >> N >> K; 
  LLI last=0;
  A[0]=0;
  REP(i, N) {
    LLI a;
    cin >> a;
    A[i+1]=a-last;
    last = a;
  }  
  A[N+1]=x-last;
  //!copy paste
  last=0;
  B[0]=0;
  REP(i, N) {
    LLI b;
    cin >> b;
    B[i+1]=b-last;
    last = b;
  }  
  B[N+1]=y-last;
  
  vector<LLI> V; 
  REP(i, N+1) REP(j, N+1){
    V.push_back(A[i+1] * B[j+1]);
  }
  sort(V.begin(), V.end(), greater<LLI>());
  cout << V[K-1] << endl; 
  //REP(i, V.size()) cout << V[i] << endl;
 
	return 0;
}
