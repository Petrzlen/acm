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

int min_x, min_y;
int max_x, max_y; 

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {-1,0,1,-1,0,1,-1,1};

set<PII> S; 
  
void solve(int x, int y){
  if(S.find(PII(x,y)) == S.end()) return; 

  min_x = min(x, min_x);
  min_y = min(y, min_y);
  max_x = max(x, max_x);
  max_y = max(y, max_y);
  
  S.erase(PII(x,y)); 
  REP(i, 8){
    solve(x + dx[i], y + dy[i]); 
  }
}

int main(){
  int N, M; 
  cin >> N >> M;
  
  REP(i, M) {
    int x, y; 
    cin >> x >> y; 
    S.insert(PII(x,y)); 
  }
  
  while(!S.empty()){
    min_x = min_y = N+1;
    max_x = max_y = -1;
    set<PII>::iterator iter = S.begin(); 
    solve(iter->first, iter->second); 
    
    if((min_x == 1 && (max_x == N || min_y == 1)) || (max_y == N && (min_y == 1 || max_x == N))){
      //cout << min_x << "," << max_x << endl;
      //cout << min_y << "," << max_y << endl;
    
      cout << -1 << endl;
      return 0; 
    }
  }
  
  cout << (N-1) * 2 << endl;
  return 0; 
}
