#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  int P[N];
  REP(i, N) cin >> P[i];
  
  int sum = 0;
  sort(P, P + N, greater<int>()); 
  REP(i, N) sum += P[i];
  
  for(int i=K-1 ; i < N ; i += K){
    sum -= P[i];
  }
  
  cout << sum << endl;
  
	return 0;
}
