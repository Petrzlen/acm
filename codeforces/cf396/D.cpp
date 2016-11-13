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

void P(int p){
  vector<int> V;
  REP(i, p) V.push_back(i); 
  
  int sum_in = 0;
  do{
    int in=0;
    REP(i, V.size()) REP(j, V.size()) in += (i < j && V[i] > V[j]); 
    sum_in += in; 
    
    //REP(i, V.size()) cout << " " << V[i]; 
    //cout << " in=" << in << " sum_in=" << sum_in << endl; 
  }while(next_permutation(V.begin(), V.end())); 
  
  cout << "p=" << p << " sum_in=" << sum_in << endl;
}

int main(){
  REP(i, 10) P(i+1); 
  
  return 0; 
}
