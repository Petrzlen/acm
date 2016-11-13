#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

#define TX 1024
#define TY 768
#define X 1500
#define Y 1200
#define D 200
#define R 50
bool M[X][Y];
int P[TX][TY];

typedef pair<int, int> PII;

int main()
{
//  cout << "START" << endl;
  REP(i, X) REP(j, Y) M[i][j]=false;

  string s;
  getline(cin, s); //cout << s;
  getline(cin, s); //cout << s;
  getline(cin, s); //cout << s; 
  REP(j,TY) { REP(i, TX){
      bool b;
      cin >> b;
      M[i+D][j+D] = !b; 
      //cout << M[i+D][j+D] << " ";
    }
//    cout << endl;
  }
//  cout << "INPUT" << endl;
  vector<PII> C; 
  for(int i=-R; i<=R; i++) for(int j=-R; j<=R; j++) if(i*i + j*j <= R*R) C.push_back(PII(i, j)); 
  
  vector<PII> CX; 
  vector<PII> CY; 
  REP(i, C.size()){
    CX.push_back(PII(C[i].first + 1, C[i].second)); 
    CY.push_back(PII(C[i].first, C[i].second + 1)); 
//    cout << C[i].first << " " << C[i].second << endl;
  }
  sort(C.begin(), C.end()); 
  sort(CX.begin(), CX.end());
  sort(CY.begin(), CY.end());
  
 // cout << "CIRCLE CONSTRUCT " << C.size() << " " << CX.size() << " " << CY.size() << endl;
  
  vector<PII> CXp(C.size()), CXm(C.size()), CYp(C.size()), CYm(C.size()); 
  vector<PII>::iterator it; 
  it=std::set_difference (CX.begin(), CX.end(), C.begin(), C.end(), CXp.begin()); CXp.resize(it-CXp.begin());   
  it=std::set_difference (C.begin(), C.end(), CX.begin(), CX.end(), CXm.begin()); CXm.resize(it-CXm.begin());   
  it=std::set_difference (CY.begin(), CY.end(), C.begin(), C.end(), CYp.begin()); CYp.resize(it-CYp.begin());   
  it=std::set_difference (C.begin(), C.end(), CY.begin(), CY.end(), CYm.begin()); CYm.resize(it-CYm.begin());   
 
  //REP(i, CXp.size()) cout << CXp[i].first << " " << CXp[i].second << endl;
 
  //cout << "CIRCLE DIFF " << CXp.size() << " " << CXm.size() << " " << CYp.size() << " " << CYm.size() << endl;
 
  int p=0;
  REP(i, C.size()) p+=M[C[i].first+D][C[i].second+D]; 
  int py=p; 
  
  REP(j, TY) {  
    int px=py; 
    REP(i, TX){
      P[i][j] = px; 
      REP(k, CXp.size()) px += M[CXp[k].first+i+D][CXp[k].second+j+D];
      REP(k, CXm.size()) px -= M[CXm[k].first+i+D][CXm[k].second+j+D];
    }
    
    REP(k, CYp.size()) py += M[CYp[k].first+D][CYp[k].second+j+D];
    REP(k, CYm.size()) py -= M[CYm[k].first+D][CYm[k].second+j+D];
  }
  
  //cout << "COUNTS" << endl;
  
  vector<PII> H; 
  REP(i, TX){
     REP(j, TY) {
      if(P[i][j] >= C.size()/2) {
        H.push_back(PII(i, j));
//        cout << i << " " << j << "\t"; 
      }
    }
    //cout << endl;
  }
  
  PII avg(0, 0); 
  REP(i, H.size()) {avg.first += H[i].first; avg.second += H[i].second;}
  avg.first /= H.size();
  avg.second /= H.size(); 
  
  cout << avg.first << " " << avg.second << endl;
  
	return 0;
}
