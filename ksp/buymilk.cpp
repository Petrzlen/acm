#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef unsigned long long int uLLI; 

set<uLLI> S1; 
set<uLLI> S2; 
uLLI M1[20];
uLLI M2[20];

int main()
{
  uLLI target;
  int n; 
  int k; 
  
  cin >> target >> n; 
  REP(i, n){
    if(i >= 20) {
      break; 
    }
    cin >> M1[i];
    k = i+1;
  }
  REP(i, n-k){
    cin >> M2[i]; 
  }
  
  REP(i, 1 << k){
    uLLI s = 0; 
    REP(j, k){
      if((1 << j) & i) {
        s += M1[j]; 
      }
    }
    S1.insert(s); 
  }
  REP(i, 1 << (n-k)){
    uLLI sum = 0; 
    REP(j, n-k){
      if((1 << j) & i) {
        sum += M2[j]; 
      }
    }
    S2.insert(sum); 
  }
  
  /*
  cout << "set 1" << endl;
  for(set<uLLI>::iterator jter = S1.begin(); jter != S1.end(); jter++)
    cout << *jter << endl;
  cout << "set 2" << endl;
  for(set<uLLI>::iterator jter = S2.begin(); jter != S2.end(); jter++)
    cout << *jter << endl; */
  
  uLLI best = 123456789123456789; 
  for(set<uLLI>::iterator jter = S2.begin(); jter != S2.end(); jter++){
    uLLI j = *jter;
    if(j >= target) best = min(best, j); 
    else{
      set<uLLI>::iterator iter = S1.lower_bound(target - j);
      if(iter != S1.end()) {
        uLLI i = *iter; 
        best = min(best, j + i);  
        //cout << best << " " << j << " " << i << endl;
      }
    }
  }
  
  cout << best << endl;

	return 0;
}
