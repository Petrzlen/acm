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

string bus[6] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int main(){
  int n; 
  cin >> n; 
  REP(i, n){
    if(i<=3) bus[i+1][1] = 'O'; 
    else {
      int k = i-4; 
      if(k%3==0 || k%3==1) bus[1+k%3][3+2*(k/3)] = 'O'; 
      else bus[4][3+2*(k/3)] = 'O'; 
    }  
  }
  
  REP(i, 6) cout << bus[i] << endl; 
  
  return 0; 
}
