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

int main(){
  int N, K; 
  cin >> N >> K; 
  
  if(2*K >= N) {
    cout << -1 << endl;
    return 0;   
  }
  
  cout << N * K << endl;
  for(int s=1; s<=K ; s++){
    vector<bool> V(N, false); 
    int v=0; 
    int i=0; 
    while(v != N){
      if(!V[i]){
        V[i]=true;
        cout << (i+1) << " " << ((i + s) % N) + 1 << endl;
        i=(i + s) % N;
        v++;  
      }
      else{
        i=(i + 1) % N; 
      }
    }
  }
  
  return 0; 
}
