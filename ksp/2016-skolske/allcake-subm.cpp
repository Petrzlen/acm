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

int bidsearch(LLI s, int aid, int frombid, int tobid){
  if(frombid + 1 == tobid) return frombid;
  
  int mid = (frombid + tobid) / 2;
  if(A[aid]*B[mid] >= s) return bidsearch(s, aid, frombid, mid); 
  else return bidsearch(s, aid, mid, tobid); 
}

void ssearch(LLI froms, LLI tos){
  LLI mid = (froms + tos) / 2;

  for(int aid=1; aid <= N+1; aid++)
    R[aid] = bidsearch(mid, aid, 0, N+2); 
    
  LLI sumk = 0;
  for(int aid=1; aid <= N+1; aid++)
    sumk += N+1 - R[aid];
    
  //cout << mid << ": " << sumk << endl; 
   
  if(froms + 1 == tos) return;
  if(sumk < K) ssearch(froms, mid);
  else ssearch(mid, tos); 
}

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
  A[N+2]=maxLLI;
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
  B[N+2]=maxLLI;
  
  sort(A, A+N+2);
  sort(B, B+N+2);
  
  ssearch(0, maxLLI); 
  
  LLI result = maxLLI;
  for(int i=1; i<=N+1; i++) result = min(result, A[i] * B[R[i]+1]);
  cout << result << endl;

  //REP(i, N+2) cout << A[i] << endl;
  //cout << "--------------" << endl;
  //REP(i, N+2) cout << B[i] << endl;
  //cout << "--------------" << endl;
  //REP(i, N+2) cout << R[i] << endl;

	return 0;
}
