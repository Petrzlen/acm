// alert: MUCH FARMER CODE 

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
typedef pair<LLI, LLI> PII; 
typedef pair<LLI, PII> PIII; 

#define INF 123456789123456789

int main(){
  LLI N;
  cin >> N;
  
  vector<PIII> V(N, PIII(0, PII(0,0))); 
  REP(i, N) cin >> V[i].first >> V[i].second.first >> V[i].second.second; 
  
  priority_queue<PIII, vector<PIII>, greater<PIII> > T; 
  REP(i, N) T.push(PIII(V[i].first, PII(1, i))); 
  
  vector<PII> B(1, PII(0, 0));  // (time, best value) 
  vector<int> Bid(1, -1); //
  map<int, int> J;
  J[-1] = -1; 
  
  //cout << "==V" << endl;
  //REP(i, V.size()) cout << V[i].first << ", (" << V[i].second.first << ", " << V[i].second.second << ")" << endl;
  
  while(!T.empty()){
    LLI w = T.top().second.first; 
    LLI t = T.top().first; 
    LLI i = T.top().second.second; 
    
    //cout << "w=" << w << " t=" << t << " i=" << i << endl;
    
    T.pop();
    
    if(w == 1){
      T.push(PIII(V[i].first + V[i].second.first, PII(0, i))); 
    }
    else{
      vector<PII>::iterator biter = lower_bound(B.begin(), B.end(), PII(V[i].first+1,-1)); 
      biter--; 
      LLI v = biter->second + V[i].second.second;
      
      if(v > B[B.size()-1].second){
        int bindex = distance(B.begin(), biter); 
        B.push_back(PII(t, v));
        Bid.push_back(i); 
        J[i] = Bid[bindex];  
        
        //cout << "  update bindex=" << bindex << " v=" << v << endl;
      }
    }
  }
  
  // debug 
  //cout << "==B" << endl;
  //REP(i, B.size()) cout << B[i].first << ", " << B[i].second << endl;
  //cout << "==J" << endl;
  //for(map<int, int>::iterator iter = J.begin(); iter != J.end() ; iter++) cout << iter->first << ", " << iter->second << endl;
  
  cout << B[B.size()-1].second << endl;
  
  int bi = Bid[Bid.size()-1]; 
  vector<int> R;
  while(bi != -1){
    R.push_back(bi); 
    bi = J[bi]; 
  }
  reverse(R.begin(), R.end()); 
  
  cout << R.size() << endl;
  REP(i, R.size()){
    if(i != 0) cout << " "; 
    cout << (R[i] + 1); 
  }
  cout << endl;
  
  return 0; 
}
