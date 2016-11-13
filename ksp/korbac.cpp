#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define X 4
#define Y 4

char M[500][600];
typedef pair<int, bool> PIB;
typedef pair<int, PIB> PIPIB; 

int main()
{
  REP(i, 500) REP(j, 600) M[i][j]=' ';

  int n, k;
  cin >> n >> k; 
  
  vector<PIPIB> K; 
  vector<int> D(n, 0);
  int I[n];
  REP(i, n) I[i]=i;  
  
  string s;
  int maxd=0;
  REP(i, k){
    cin >> s;
    
    int p=I[s[1]-'1']; 
    bool b=s[0]=='+';
    int d=max(D[p],D[p+1]);
    
    //cout << d << "," << p << ":" << b << endl;
    
    maxd=max(maxd,d+1); 
    K.push_back(PIPIB(d, PIB(p,b)));
    
    D[p]=d+1;
    D[p+1]=d+1;
    //swap(I[p], I[p+1]);
  }
  
  REP(i, K.size()){
    int d=K[i].first; 
    int p=K[i].second.first; 
    bool b=K[i].second.second; 
    d *= 4;
    p *= 4;
    
    M[X+d+1][Y+p+1]='\\';
    M[X+d+1][Y+p+3]='/';
    M[X+d+2][Y+p+2]=(b) ? '\\' : '/';
    M[X+d+3][Y+p+1]='/';
    M[X+d+3][Y+p+3]='\\';
  }
 
  for(int i=1; i<500; i++){
    for(int j=4; j<500; j+=4){
      if(M[i-1][j-1]=='\\' && M[i+1][j+1]=='\\'){
        M[i][j]='\\';
      }
      if(M[i-1][j+1]=='/' && M[i+1][j-1]=='/'){
        M[i][j]='/';
      }
      if(M[i][j]==' '){
        bool b=true; 
        for(int a=j-2; a<=j+2 ; a++){
          if(M[i][a]!=' '){
            b=false;
          }
        }
        if(b){
          M[i][j]='|';
        }
      }
    }
  }
 
  REP(i, maxd*4+1){
    REP(j, n*4-3) {
      cout << M[X+i][Y+j];
    }
    cout << endl;
  }
  
	return 0;
}
