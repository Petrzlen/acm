#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

#define MAX 1234567

int n; 
vector<int> N[MAX]; 
bool B[MAX];
int D[MAX]; 

int max_dist(int from){
  REP(i, n+1) D[i]=MAX; 
  
  queue<pair<int, int> > Q;
  Q.push(pair<int, int>(from, 0)); 
  
  while(!Q.empty()){
    pair<int, int> v=Q.front();
    Q.pop(); 
    
    if(D[v.first]<MAX) continue; 
    D[v.first]=v.second; 
    
    REP(i, N[v.first].size()) Q.push(pair<int, int>(N[v.first][i], v.second+1)); 
  }
  
  pair<int, int> r(0, from);
  REP(i, n) if(B[i+1]) r = max(r, pair<int, int>(D[i+1], i+1));
  
  return r.second; 
}

int main()
{
  cin >> n; 

  int bi;
  REP(i, n){
    cin >> B[i+1];  
    if(B[i+1]) bi=i+1; 
  }
  
  REP(i, n-1){
    int a,b;
    cin>>a>>b;
    N[a].push_back(b);
    N[b].push_back(a);
  }
  
  int mdi = max_dist(bi); 
  //cout << bi << "->" << mdi << "->" << max_dist(mdi) << endl;
  mdi = max_dist(mdi);
  
  cout << (D[mdi]+1) / 2 << endl; 
  
	return 0;
}
