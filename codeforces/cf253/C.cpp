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
#include <complex> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
#define EPS 1e-6

typedef long long int LLI;
typedef pair<int, int> PII; 
typedef complex<double> CD; 

CD rc(){
  double r, i; 
  cin >> r >> i;
  return CD(r, i); 
}

int main(){
  int T; 
  cin >> T;
  vector<double> V; 
  
  REP(t, T){
    CD A[4];
    REP(i, 4) A[i] = rc(); 
    bool is_circle = abs(abs(A[0]-A[1]) - abs(A[2]-A[3])) < EPS; 
    
    CD rot = conj(A[0] - A[1]); 
    rot /= abs(rot); 
    REP(i, 4) A[i] *= rot; 
    
    double scalex = 2.0 / abs(A[0] - A[1]); 
    REP(i, 4) A[i] = CD(scalex*real(A[i]), imag(A[i])); 
    
    double scaley = (is_circle) ? scalex : 2.0 / abs(A[2] - A[3]); 
    REP(i, 4) A[i] = CD(real(A[i]), scaley * imag(A[i]));
    
    //REP(i, 4) cout << i << ": " << A[i] << endl;
    //cout << "is_circle=" << is_circle << endl;
    //cout << "rot=" << rot << endl;
    //cout << "scalex=" << scalex << endl;
    //cout << "scaley=" << scaley << endl;
    
    int M; 
    cin >> M;
    double sum=0.0; 
    REP(m, M){
      CD R[4]; 
      REP(i, 4) R[i] = rc() * rot; 
      REP(i, 4) R[i] = CD(scalex*real(R[i]), imag(R[i])); 
      REP(i, 4) R[i] = CD(real(R[i]), scaley * imag(R[i]));
      
      vector<double> D; 
      REP(i, 4) REP(j, 4) if(i<j) D.push_back(abs(R[i]-R[j])); 
      sort(D.begin(), D.end()); 
      sum += D[1] * D[2]; 
      
      //cout << "rect " << D[1] << ":" << D[2] << endl;
      //REP(i, 4) cout << "  " << R[i] << endl;
    }
    
    V.push_back(sum); 
  }
  
  int g = 1; 
  vector<pair<double, int> > S;
  REP(i, V.size()) S.push_back(pair<double, int>(V[i], i)); 
  sort(S.begin(), S.end()); 
  
  vector<int> R(S.size(), 0); 
  REP(i, S.size()) {
    //cout << i << " : " << S[i].first << endl;
    if(i > 0 && abs(S[i].first - S[i-1].first) > EPS) g++; 
    R[S[i].second] = g;
  }
  
  REP(i, R.size()) {
    if(i != 0) cout << " ";
    cout << R[i]; 
  }
  cout << endl;
  return 0; 
}
