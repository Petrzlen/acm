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

#define PIPKOS -500600

LLI mm(vector<LLI>& V){
  return *max_element(V.begin(), V.end()) - *min_element(V.begin(), V.end());
}

vector<LLI> bs(LLI w, LLI h, int i, LLI from, LLI to); 

vector<LLI> slice(LLI w, LLI h, int i, LLI at){
  if(i==0) return vector<LLI>(); 
  if(i==1) return vector<LLI>(1, w*h);
  
  LLI m = 123456789123; 
  map<LLI, vector<LLI> > M; 
  
  for(int j=1; j<i; j++){
    vector<LLI> L1 = bs(at, h, j, 1, at+1); 
    vector<LLI> R1 = bs(w-at, h, i-j, 1, w-at+1); 
    vector<LLI> A1(L1.begin(), L1.end()); 
    A1.insert(A1.end(), R1.begin(), R1.end()); 
    LLI mi = mm(A1); 
    M[mi]=A1;
    m = min(m, mi); 
    
    vector<LLI> L2 = bs(h, at, j, 1, h+1); 
    vector<LLI> R2 = bs(h, w-at, i-j, 1, h+1); 
    vector<LLI> A2(L2.begin(), L2.end()); 
    A2.insert(A2.end(), R2.begin(), R2.end()); 
    mi = mm(A2); 
    M[mi]=A2;
    m = min(m, mi); 
  } 
  
  return M[m]; 
} 

//1 <= from < to <= w+1
//seeks from optimal division of w x h cutting w into (w-m) x h and m x h to i parts 
vector<LLI> bs(LLI w, LLI h, int i, LLI from, LLI to){
  REP(j, 6-i) cout << "  ";
  cout << "bs " << w << "," << h << "," << i << "," << from << "," << to << endl;

  //safety
  if(w<=0 || h<=0) return vector<LLI>(1,PIPKOS); 
  if(from<1) return vector<LLI>(1,PIPKOS);
  if(to>w+1) return vector<LLI>(1,PIPKOS); 
  
  if(i==1) return vector<LLI>(1,w*h); 
  
  //i>1
  
  if(from + 1 >= to){
    return slice(w, h, i-1, from); 
  }
  
  vector<LLI> A1;
  vector<LLI> A2;
  LLI m2 = (from + to) / 2; 
  LLI m1 = m2-1; 
  
  A1 = slice(w,h,i-1,m1); 
  A2 = slice(w,h,i-1,m2); 
  
  if(mm(A1)<mm(A2)){
    cout << "chosen m1 " << m1 << endl;
    return bs(w, h, i, from, m1+1); 
  }
  else{
    cout << "chosen m2 " << m2 << endl;
    return bs(w, h, i, m2, to); 
  }
}

int main(){
  LLI R, S, N;
  cin >> R >> S >> N; 
  
  vector<LLI> A1 = bs(R,S,N+1,1,R+1); 
  vector<LLI> A2 = bs(S,R,N+1,1,S+1);  
  
  if(find(A1.begin(), A1.end(), PIPKOS) != A1.end() 
  && find(A2.begin(), A2.end(), PIPKOS) != A2.end()) {
    cout << -1 << endl;
  }
  
  LLI result = min(mm(A1),mm(A2)); 
  cout << result << endl;

  return 0; 
}

