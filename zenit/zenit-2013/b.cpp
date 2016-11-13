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
  int P, L, N; 
  cin >> P >> L >> N; 
  
  REP(i, N){
    string s;
    cin >> s;
    int p;
    cin >> p; 
    
    if(p*L>=P) cout << "oplati" << endl;
    else cout << "neoplati" << endl;
  }
  
  return 0; 
}
