#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef pair<int, int> PII;

int N;
bool e[543210];
PII V[543210];
PII Z[543210];


int main()
{
  cin >> N;
  REP(i, N){
    int a, b;
    cin >> a >> b;
    e[i]=false;
    V[i]=PII(a, i);
    Z[i]=PII(a/b + 1, i); 
  }
  sort(Z, Z+N, greater<PII>());
  sort(V, V+N, greater<PII>());
  
  int result = 0;
  int z=0;
  int v=0; 
  while(z<N){
    result++;
    while(v<N && V[v].first >= Z[z].first) {
      //cout << Z[z].first << ": " << V[v].first << endl;
      e[V[v].second]=true;
      v++;
    }
  
    while(z<N && e[Z[z].second]) z++;
  }

  cout << result << endl;

	return 0;
}
