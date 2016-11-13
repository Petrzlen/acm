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
  int r,c,s,k;
  string line; 
  cin >> r >> c >> s >> k;
  cin >> line; 
  
  int start=123456, end=-1;
  int count; 
  REP(i, line.size()){
    if(line[i]=='*') {
      start=min(start, i+1);
      end=max(end, i+1);
      count++;
    }
  }
  
  if(end-start+1 != count){
    cout << "nemozne" << endl;
    return 0; 
  } 
  
  int pos=0; 
  for(int i=1; i<=r-s+1; i++){
    for(int j=1; j<=c-s+1; j++){
      if(j==start && j+s-1==end && k>=i && k<=i+s-1) {
        pos++; 
      }
    }
  }
 
  if(pos==0) cout << "nemozne" << endl; 
  if(pos==1) cout << "jednoznacne" << endl;
  if(pos >1) cout << "nejednoznacne" << endl;
  
	return 0;
}
