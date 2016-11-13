#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define INF 1234567890123456789ll
typedef long long int LLI; 

LLI A,B,K;
int N; 
vector<LLI> X, Y;
LLI result;

void citaj(LLI up, vector<LLI>& V){
  LLI last=0;
  REP(i, N){
    LLI x;
    cin >> x;
    V.push_back(x-last);
    last = x;
  }
  V.push_back(up-last); 
}

void search(LLI from, LLI to){
  LLI mid = (from + to - 1) / 2;
  LLI vecsie=0; 
  result=0;
  int j=0;
  REP(i, X.size()){
    while(j<Y.size() && X[i]*Y[j] > mid) {
      j++;
    }
    vecsie += j; 
    result = max(result, X[i]*Y[j]);  
  } 
  //cout << from << "->" << to << " m:" << mid << ": " << vecsie << endl;
  
  if(from + 1 == to) return; 
  if(vecsie < K) search(from, mid+1);
  else search(mid+1, to); 
}

int main()
{
  cin >> A >> B >> N >> K;  
  citaj(A,X);
  citaj(B,Y);
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end(), greater<LLI>());
    
  search(0, INF); 
  cout << result << endl;   
    
	return 0;
}
