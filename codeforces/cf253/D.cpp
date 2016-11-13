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
#include <complex> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

void coutArr(vector<int>& v){
  REP(j, v.size()){
    if(j != 0) cout << " "; 
    cout << v[j]; 
  }
  cout << endl << flush; 
}

void solve(){
  int N;
  cin >> N; 
  
  vector<int> T(N, 3); 
  REP(i, N){
    cout << 1 << endl;
    cout << i+1 << endl << flush; 
    cin >> T[i]; 
    T[i] = 2 - T[i]; 
  }
  
  REP(i, N){
    vector<int> A; 
    REP(j, N) if(T[i] != T[j]) A.push_back(j+1); 
    A.push_back(i+1); 
    cout << A.size() << endl;
    coutArr(A);  
    
    int x;
    cin >> x;
    if(x == 0 || x == A.size()) T[i] = 3; 
  }
  
  cout << -1 << endl;
  coutArr(T); 
}

int main(){
  int T;
  cin >> T;
  REP(i, T) solve(); 
  return 0; 
}
