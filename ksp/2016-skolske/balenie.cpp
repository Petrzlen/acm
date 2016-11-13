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

#define MAX 100

int count(string s, char c){
  int result = 0; 
  REP(i, s.size()) result += s[i] == c; 
  return result;
}

vector<vector<int> > LN; 

int isLN(vector<int>& v){
    vector<int> L(4,0);
    //REP(i, LN.size()) REP(j, LN[i].size()) cout << i << j << endl;
    
    for(int a=-MAX ; a<=MAX ; a++) for(int b=-MAX ; b<=MAX ; b++) for(int c=-MAX ; c<=MAX ; c++){
      REP(i, 4) {
        L[i] = a*LN[0][i] + b*LN[1][i] + c*LN[2][i];
      }
      if(L[0] == v[0] && L[1] == v[1] && L[2] == v[2]) {
        return L[3]; 
      } 
    }
    return -1;
}
  
int main()
{
  vector<vector<int> > V; 

  int j, y; 
  cin >> j >> y; 
  
  int ca=0, cb=0, cc=0; 
  
  REP(fdsa, j) {
    string s; 
    cin >> s; 
    
    int d=0;
    for(int i=0; i<s.size() && s[i]=='.' ; i++) d=i+1; 
    
    vector<int> L; 
    L.push_back(ca); 
    L.push_back(cb); 
    L.push_back(cc); 
    L.push_back(d); 
    for(int div=2; div <= MAX ; div++){
      if(L[0]%div == 0 && L[1]%div==0 && L[2]%div==0){
        REP(i, 4) L[i] /= div; 
      }
    }
    
    V.push_back(L); 
    
    ca += count(s, '('); 
    cb += count(s, '['); 
    cc += count(s, '{');
    
    ca -= count(s, ')');
    cb -= count(s, ']');
    cc -= count(s, '}');
  }
 
  LN.push_back(vector<int>(4,0)); 
  LN.push_back(vector<int>(4,0)); 
  LN.push_back(vector<int>(4,0)); 
  int LNi=0; 
  
  for(int v=0; v<V.size() ; v++){
    //cout << V[v][0] << "," << V[v][1] << "," << V[v][2] << "," << endl;
  
    if((V[v][0]!=0 || V[v][1]!=0 || V[v][2]!=0) && isLN(V[v]) < 0){
      //cout << V[v][0] << "," << V[v][1] << "," << V[v][2] << "," << V[v][3] << endl;
      LN[LNi++] = V[v]; 
    }
  }
 
  ca=0;
  cb=0;
  cc=0; 
  
  REP(fdsa, y) {
  
    string s; 
    cin >> s; 
    
    vector<int> L; 
    L.push_back(ca); 
    L.push_back(cb); 
    L.push_back(cc); 
   
    //cout << ca << ", " << cb << ", " << cc << endl;
    
    cout << isLN(L) << endl;
       
    ca += count(s, '('); 
    cb += count(s, '['); 
    cc += count(s, '{');
    
    ca -= count(s, ')');
    cb -= count(s, ']');
    cc -= count(s, '}');
  }
  
	return 0;
}
