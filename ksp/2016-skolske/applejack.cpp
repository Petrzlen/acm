#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef pair<int, int> PII;
typedef pair<PII, PII> BOD;
map<int, int> X;
map<int, int> Y; 
vector<int> Xove;
vector<int> Yove;
vector<BOD> B; 

#define SIZE 256
char M[SIZE][SIZE];

void R(BOD& b){
  int x1,y1,x2,y2;
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;
  b.first.first = min(x1,x2);
  b.second.first = max(x1,x2);
  b.first.second = min(y1,y2);
  b.second.second = max(y1,y2);
}

void T(BOD& b){
  b.first.first = X[b.first.first];
  b.second.first = X[b.second.first];
  b.first.second = Y[b.first.second];
  b.second.second = Y[b.second.second];
}

void V(int x1, int y1, int x2, int y2, char c){
  for(int a=x1; a<x2; a++)
    for(int b=y1; b<y2; b++)
      M[a][b]=c; 
}

int S(int x, int y){
  if(x<0 || x>=SIZE || y<0 || y >= SIZE) return 0; 
  if(M[x][y]!='K') return 0;
  M[x][y] = 'X';
  
  S(x-1, y);
  S(x+1, y);
  S(x, y-1);
  S(x, y+1);
  
  return 1;
}

int main()
{
  BOD D; 
  R(D); 
  Xove.push_back(D.first.first);
  Xove.push_back(D.second.first);
  Yove.push_back(D.first.second);
  Yove.push_back(D.second.second);
    
  int N;
  cin >> N;
  REP(i, N){
    BOD A; 
    R(A); 
    B.push_back(A);
    Xove.push_back(A.first.first);
    Xove.push_back(A.second.first);
    Yove.push_back(A.first.second);
    Yove.push_back(A.second.second);
  }
  
  sort(Xove.begin(), Xove.end());
  sort(Yove.begin(), Yove.end());
  
  int k=0;
  REP(i, Xove.size()) if(X.count(Xove[i])==0) X[Xove[i]] = k++;
  k=0;
  REP(i, Yove.size()) if(Y.count(Yove[i])==0) Y[Yove[i]] = k++;
  
  T(D);
  REP(i, B.size()) T(B[i]); 
  
  REP(i, SIZE) REP(j, SIZE) M[i][j]='O'; 
  
  V(D.first.first, D.first.second, D.second.first, D.second.second, 'K');
  REP(i, B.size()) V(B[i].first.first, B[i].first.second, B[i].second.first, B[i].second.second, 'X');
  
  //REP(j, 40) {REP(i, 40) cout << M[i][j]; cout << endl;}
  
  int result=0;
  REP(i, SIZE) REP(j, SIZE) result += S(i, j); 
  
  cout << result << endl;
  
	return 0;
}
