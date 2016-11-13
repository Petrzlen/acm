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
typedef pair<double, double> PDD; 

PDD move(PDD A, PDD B, double x){
  PDD result = A;
  result.first = x;
  result.second = A.second + (B.second - A.second) * ((x-A.first)/(B.first - A.first)); 
  return result; 
}

int main(){
  int N, K;
  cin >> N >> K; 
  
  vector<PDD> old; 
  REP(i, K+1) old.push_back(PDD(i, 0.0)); 
  
  vector<PDD> buffer; 
  
  REP(i, N){
    vector<PDD> line(K+1, PDD(0,0)); 
    REP(j, K+1) {cin >> line[i].second; line[i].first = i;}
    
    double result = 0; 
    int io = 1; 
    int il = 1; 
    
    cout << "i=" << i << " line.size()=" << line.size() << " old.size()=" << old.size() << endl;
    
    while(io < old.size() && il < line.size()){
      cout << "io=" << io << " il=" << il << endl;
    
      if(old[io].first < line[il-1].first){
        io++;
        continue;
      }
      if(line[il].first < line[io-1].first){
        il++;
        continue;
      }
      
      PDD AA = old[io-1]; 
      PDD AB = old[io];
      PDD BA = line[il-1]; 
      PDD BB = line[il]; 
      
      double a = max(AA.first, BA.first); 
      double b = min(AB.first, BB.first); 
      
      cout << "a=" << a << " b=" << b << endl;
      
      AA = move(AA, AB, a); 
      AB = move(AB, AA, b); 
      BA = move(BA, BB, a);
      BB = move(BB, BA, b); 
      
      double A1 = AB.second - AA.second;
      double B1 = -(AB.first - AA.first); 
      double C1 = -(A1*AA.first + B1*AA.second); 
      
      double A2 = BB.second - BA.second;
      double B2 = -(BB.first - BA.first); 
      double C2 = -(A2*BA.first + B2*BA.second); 
      
      bool is = true; 
      double x;
      double y; 
      
      double delta = A1*B2 - A2*B1; 
      if(delta == 0.0) is = false;
      
      if(is){
        x = (B2*C1 - B1*C2)/delta; 
        y = (A1*C2 - A2*C1)/delta; 
        is = (a <= x && x <= b); 
      }
      
      if(is){
        if(BA.second > AA.second) result += ((BA.second-AA.second)/2.0) * (x - a);
        if(BB.second > AB.second) result += ((BB.second-AB.second)/2.0) * (b - x);
        buffer.push_back(PDD(x,y)); 
      }
      else{
        if(BA.second >= AA.second && BB.second >= AB.second){
          result += ((BA.second-AA.second + BB.second-AB.second) / 2.0) * (b - a); 
        }
      }
      
      buffer.push_back((BA.second > AA.second) ? BA : AA); 
      buffer.push_back((BB.second > AB.second) ? BB : AB);
      
      if(old[io-1].first < line[il-1].first) io++; 
      else il++;  
    }
    
    sort(buffer.begin(), buffer.end()); 
    old = buffer; 
    cout << result << endl;
  }
  
  
  return 0; 
}
