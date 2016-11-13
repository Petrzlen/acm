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
#include <iomanip> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, LLI> PII; 
typedef long double LD; 

#define M 2048
LD P[2][M][M]; 

int main()
{
  REP(z, 2) REP(i, M) REP(j, M) P[z][i][j] = 0; 
  P[1][0][0] = 1; 
  
  int N;
  cin >> N; 
  
  REP(n, N){
    int v;
    cin >> v; 
    
    int z = n%2; 
    int y = (z+1)%2; 
    REP(i, M) REP(j, M) P[z][i][j] = P[y][i][j] / 2.0; 
    REP(i, M) REP(j, M) if(P[y][i][j] != 0) P[z][max(i,j+v)][max(0, j+v)] += P[y][i][j] / 2.0; 
  }
  
  int r = (N+1) % 2; 
  LD result = 0.0; 
  REP(i, M) REP(j, M) result += i * P[r][i][j]; 
  
  cout << setprecision(12) << result << endl;
  
	return 0;
}
