#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <sstream> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int n;
  string line; 
  map<string, set<string> > b; 
  map<string, set<string> > f; 
  
  cin >> n; 
  
  REP(i, n+1){
    getline(cin, line);
    stringstream ss(line); 
    
    string word; 
    string expl;
    ss >> word; 
    while(ss >> expl){
      b[expl].insert(word);
    } 
    b[word]; //allocate
  }
  
  bool found=true;
  while(found){
    found=false; 
    for(map<string, set<string> >::iterator bter = b.begin() ; bter != b.end() ; bter++){
      if(bter->second.empty()){
        found=true; 
        
        for(map<string, set<string> >::iterator dter = b.begin() ; dter != b.end() ; dter++){
          dter->second.erase(bter->first); 
        }
        
        b.erase(bter); 
        break;
      }
    }
  }
  
  vector<string> result;
  for(map<string, set<string> >::iterator bter = b.begin() ; bter != b.end() ; bter++){
    result.push_back(bter->first);
  }
  sort(result.begin(), result.end()); 
 
  cout << result.size() << endl; 
  REP(i, result.size()){
    if(i!=0) cout << " ";
    cout << result[i]; 
  }
  cout << endl;
  
	return 0;
}
