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
//typedef pair<PII, PII> P22; 
//typedef pair<LLI, PPIIPII> P122; 

int main()
{
  int N; 
  cin >> N;
  
  
  vector<pair<LLI, PII> > B; //original
  map<pair<LLI, PII>, int > F; //first occurence
  map<pair<LLI, PII>, int > M; //counts
  
  REP(n, N){
    vector<LLI> S(3,0); 
    REP(i, 3) cin >> S[i];
    B.push_back(pair<LLI, PII>(S[0], PII(S[1], S[2]))); 
    
    sort(S.begin(), S.end()); 
    pair<LLI, PII> k(S[0], PII(S[1], S[2])); 
    M[k]++;
    if(M[k]==1) F[k]=n; 
  }
  
  vector<pair<int, PII> > V;
  for(map<pair<LLI, PII>, int >::iterator iter = M.begin() ; iter != M.end() ; iter++){
    pair<LLI, PII> p = iter->first; //krabica s usporiadanymi objemami 
    //-pocet, -objem, cislo prveho vyskytu
    V.push_back(pair<int, PII>(-iter->second, PII(-p.first * p.second.first * p.second.second, F[iter->first])));
  }
  
  sort(V.begin(), V.end());
  
  REP(i, V.size()){
    int id = V[i].second.second;
    int count = -V[i].first;  
    if(count > 1){
      cout << B[id].first << "x" << B[id].second.first << "x" << B[id].second.second << " " << count << endl;
    }
  } 
  
	return 0;
}
