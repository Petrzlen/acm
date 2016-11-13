#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int N, Z;
  cin >> N >> Z;
  
  map<int, vector<int> > M;
  REP(i, N){
    int x;
    cin >> x;
    M[x].push_back(i);
  } 
  
  int best=0; 
  for(map<int, vector<int> >::iterator iter = M.begin(); iter != M.end() ; ++iter){
//    cout << iter->first << " size=" << iter->second.size() << endl;
  
    vector<int> V; 
    for(int i=1; i<iter->second.size(); ++i) V.push_back(iter->second[i]-iter->second[i-1]-1); 
    vector<int> P;
    P.push_back(0);
    REP(i, V.size()) P.push_back(P[i]+V[i]);     
    P.push_back(123456789);
    
//    REP(i, P.size()) cout << P[i] << " ";
//    cout << endl;
    
    int j=0; 
    for(int i=0; i<P.size()-1; i++){
      while(P[j]-P[i] <= Z) {
//        cout << i << "," << j << " " << P[i] << "," << P[j+1] << endl;
        best = max(best, min(N, j-i+1 + Z)); 
        j++; 
      }
      j--;
    }
  }
  
  cout << best << endl;
  
	return 0;
}
