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
  int N;
  cin >> N;
  REP(i, N){
    string s;
    cin>>s;
    REP(j, s.size()) if(s[j]>='a' && s[j]<='z') s[j] += 'A'-'a'; 
    
    set<char> sl;
    sl.insert('A');
    sl.insert('J');
    sl.insert('L');
    sl.insert('P');
    sl.insert('R');
    sl.insert('W');
    
    set<char> l;
    l.insert('B');l.insert('C');l.insert('D');
    l.insert('G');l.insert('K');l.insert('M');l.insert('N');l.insert('O');l.insert('Q');l.insert('T');
    l.insert('X');l.insert('Y');l.insert('Z');
    
    bool result=false;
    result = result || ((s[0]=='C' && (s.size()<2 || s[1] != 'H'))||s[0]=='K'||s[0]=='Y');
    if(s.size()>1){
      if(s[0]=='N') result = result || (l.find(s[1]) != l.end());
      if(s[0]=='T' && s[1]=='E') result = result || (s.size()>2 && l.find(s[2]) != l.end());
      if(s[0]=='T' && s[1]!='E') result = result || (sl.find(s[1]) != sl.end());
    } 
    
    cout << ((result)?"ano":"nie") << endl;
  }
	return 0;
}
