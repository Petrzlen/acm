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

#define MAX 200
#define C 150
bool G[MAX][MAX];  

void add_edge(int i, int j){
  G[i][j] = G[j][i] = true;
}

int main(){
  //initialize
  REP(i, MAX) REP(j, MAX) G[i][j] = false; 

  //read input
  LLI k;
  cin >> k;
  
  //construct template
  add_edge(1,2);
  add_edge(1,3); 
  
  //  chain
  for(int i=1; i*2 < C - 4 ; i++){
    add_edge(i*2, (i+1)*2);
    add_edge(i*2, (i+1)*2 + 1);
    
    add_edge(i*2 + 1, (i+1)*2);
    add_edge(i*2 + 1, (i+1)*2 + 1);
  }
  //  path 
  add_edge(0, C); 
  for(int i=C; i<MAX; i++){
    add_edge(i, i+1); 
  }
  
  //connect first node 
  for(int i=1; k > 0 ; i++){
    if(k%2 == 1){
      add_edge(MAX-i, i*2);
    }
    k /= 2; 
  }
  
  //output
  cout << MAX << endl;
  REP(i, MAX) {REP(j, MAX) cout << ((G[i][j])?'Y':'N'); cout << endl;} 
  
  return 0; 
}
