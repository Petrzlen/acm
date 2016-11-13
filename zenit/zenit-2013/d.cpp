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
  string s1, s2;
  cin >> s1 >> s2; 
  
  if(s1 == s2){
    cout << "rovnake" << endl;
    return 0; 
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  
  if(s1 == s2){
    cout << "podobne" << endl;
  }
  else{
    cout << "odlisne" << endl;
  }
  
  return 0; 
}
