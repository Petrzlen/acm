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

/*
1: 1
2: 2
3: 3
4: 5
5: 6
6: 8
7: 11
8: 16
9: 17
10: 19
11: 22
12: 27
13: 32
14: 40
15: 51
16: 67
17: 68
18: 70
19: 73
20: 78
21: 83
22: 91
23: 102
24: 118
25: 127
*/
int test(int t){
  int result = 0; 
  
  map<int, int> M; 

  vector<int> B(t+1, 0);
  B[0]=1; //skip empty set
   
  REP(i, (1 << t) - 1){
    bool all = true; 
    
    REP(a, t) REP(b, t) if(B[a] && B[b]) {
      int x = a^b; 
      all = all && (x < t); 
      all = all && (B[x]); 
    }
    if(all){
      result++; 
      int c=0;
      REP(j, t) c+=B[j]; 
      M[c]++; 
      
      /* 
      REP(j, t) {
        if(B[j]) {
          REP(b, t) cout << ((j & (1 << b)) ? 1 : 0);
          cout << "\t";
        } 
      }
      cout << endl; */ 
    }
    
    //add one 
    B[0] += 1; 
    REP(j, t) if(B[j]==2) {
      B[j] = 0;
      B[j+1]++; 
    }
  } 
  
  cout << "t=" << t << " result=" << result << endl; 
  for(map<int, int>::iterator iter = M.begin() ; iter != M.end() ; iter++){
    cout << "  b=" << iter->first << ":" << iter->second << endl;
  }
  
}

int main(){
  for(int i=1; i<20; i++){
    test(i);
  }

  return 0; 
}
