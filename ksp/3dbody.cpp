#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

LLI** create(){
  LLI** result = new LLI*[3];
  REP(i, 3) result[i] = new LLI[3];
  return result; 
}

LLI** rep_col(LLI** A, int j, LLI val){
  LLI** result = create();
  REP(i,3) REP(k,3) result[i][k]=A[i][k]; 
  REP(i,3) result[i][j] = val;
  return result; 
}
LLI det(LLI** A){
  return 
  A[0][0]*A[1][1]*A[2][2] +
  A[0][1]*A[1][2]*A[2][0] +
  A[0][2]*A[1][0]*A[2][1] -
  A[0][0]*A[1][2]*A[2][1] -
  A[0][1]*A[1][0]*A[2][2] -
  A[0][2]*A[1][1]*A[2][0];
}

int main()
{
  bool result=true; 
  int N;
  cin >> N; 
  LLI** R = create(); 
  LLI A,B,C,D;  
  int r=0;
  REP(i, N){
    if(r<3){
      cin >> R[r][0] >> R[r][1] >> R[r][2]; 
      r++;
      if(r==3){
        A=det(rep_col(R,0,1));
        B=det(rep_col(R,1,1));
        C=det(rep_col(R,2,1));
        D=-det(R); 
        if(A==0 && B==0 && C==0){
          r=2;
        }
        //REP(i, 3) {REP(j,3) cout << R[i][j] << " "; cout << endl;}
        //cout << A << "x " << B << "y " << C << "z " << D << endl; 
      }
    }
    else{
      LLI x,y,z;
      cin >> x >> y >> z;
      result = result && (A*x+B*y+C*z+D == 0);
    }
  }
  cout << (result ? "ano" : "nie") << endl; 
  
	return 0;
}
