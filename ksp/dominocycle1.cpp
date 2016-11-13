#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int S[1234567];

int find(int a){
  int oa=a; 

  while(S[a]!=a) a = S[a]; 
  while(S[oa]!=oa) {
    int b=oa;
    oa = S[oa];
    S[b]=S[a];
  }
  return S[a];
}

void un(int a, int b){
  int sa=find(a);
  int sb=find(b); 
  S[sa]=sb; 
}

map<int, int> C;
typedef pair<int, int> PII; 
set<PII> P; 
map<PII, pair<PII, PII> > orig; 
  
void toout(vector<vector<PII> > &M, PII p, PII a, PII b){
  M[a.first][a.second]=orig[p].first; 
  M[b.first][b.second]=orig[p].second; 
}
  
void road(int n){

  vector<PII> R; 
  PII p(-1,-1); 
  while(!P.empty()){
    if(p.first<0) {
      p = *(P.begin());  
    }
    else{
      if(P.find(PII(p.second, p.second)) != P.end()) p = PII(p.second, p.second); 
      else p = *(P.lower_bound(PII(p.second, 0))); 
    }
    R.push_back(p);
    P.erase(p);
    P.erase(PII(p.second, p.first)); 
  }
  
//  REP(i, R.size()) cout << R[i].first << R[i].second << endl;

  vector<vector<PII> > M; 
  REP(i,3) {
    M.push_back(vector<PII>()); 
    REP(j,n) M[i].push_back(PII(-1, -1));
  }
  
  int mid=(n%2==0)?(n/2):(n/2+1); 
  PII midpos=(n%2==0)?PII(1, n/2):PII(0, n/2+2); 
  toout(M, R[0], PII(0,0), PII(1,0)); 
  toout(M, R[mid], PII(midpos.first+1, midpos.second), midpos);
  
  for(int i=1; i<mid; i++) toout(M, R[i], PII(2,i*2-2), PII(2, i*2-1));
  int t=2*(n-mid-1); 
  for(int i=1; i+mid<n; i++) toout(M, R[i+mid], PII(0, t-i*2+2), PII(0, t-i*2+1)); 
  
  cout << n << " " << 3 << endl; 
  REP(j, n){
    REP(i, 3){
      if(i>0) cout << " "; 
      PII p=M[i][j];
      if(p.first<0) cout << "-";
      else cout << p.first+1 << ((p.second==0)?'A':'B');
    }
    cout << endl;
  }
}  
  
int main()
{
  REP(i, 1234567) S[i]=i; 

  int n;
  cin >> n;
  
  REP(i, n){
    int a, b;
    cin >> a >> b; 
    C[a]++;
    C[b]++; 
    P.insert(PII(a,b));
    P.insert(PII(b,a)); 
    orig[PII(a,b)]=pair<PII,PII>(PII(i, 0), PII(i, 1));
    orig[PII(b,a)]=pair<PII,PII>(PII(i, 1), PII(i, 0));
    
    un(a,b); 
  }  

  bool result=true;
  set<int> qwer; 
  
  for(map<int, int>::iterator iter = C.begin(); iter != C.end(); iter++){
    if(iter->second % 2 != 0) result = false;
    qwer.insert(find(iter->first)); 
    qwer.insert(find(iter->second)); 
  }
  if(n < 4) result = false;
  if(qwer.size() != 1) result = false; 
 
  if(result){
    road(n);    
  }
  else{
    cout << "0 0" << endl;
  }

	return 0;
}
