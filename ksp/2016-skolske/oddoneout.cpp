#include <iostream>

#include <map>
#include <cstdio> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

int main()
{
	LLI N;
	map<LLI, LLI> M;
	cin >> N;
	REP(i, N) {
		LLI x;
		cin >> x;
		M[x]++; 
	}

	for(map<LLI, LLI>::iterator iter = M.begin() ; iter != M.end(); iter++){
		if(iter->second % 2 == 1){
			cout <<iter->first << endl;
			break;
		}
	}
	return 0;
}
