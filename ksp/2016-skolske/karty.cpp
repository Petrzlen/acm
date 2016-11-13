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

//kolko kariet som uz potiahol
double P[321][321][3][3];

int main()
{
  int n; 
  REP(a,321) REP(b, 321) REP(c, 3) REP(d, 3) P[a][b][c][d] = 0.0; 
  cin >> n;
  
  //a,b,c,d - kolko kariet mi este zostava
  REP(a, n+1) REP(b, n+1) REP(c, 2) REP(d, 2) {
    if(a+b+c+d == 0) continue; 
    
    double stop = (n-a) - (n-b) + (1-c)*5 - (1-d)*5; 
    double go = a*P[n-a+1][n-b][1-c][1-d]
              + b*P[n-a][n-b+1][1-c][1-d]
              + c*P[n-a][n-b][1-c+1][1-d]
              + d*P[n-a][n-b][1-c][1-d+1];
    go /= (double)(a + b + c + d); 
    
    P[n-a][n-b][1-c][1-d] = max(stop, go); 
  }
  
  //cout << setprecision(12) << P[0][0][0][0] << endl;
  printf("%.12lf\n", P[0][0][0][0]);
  
	return 0;
}
