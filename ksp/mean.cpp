#include <iostream>
#include <string> 
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

int main()
{
	int N;
	string s1, s2; 

	cin >> N >> s1 >> s2;
	bool mean=false, median=false, modus=false;

	if(s1=="mean"||s2=="mean") mean = true;
	if(s1=="mode"||s2=="mode") modus = true;
	if(s1=="median"||s2=="median") median = true;

	if(mean && median){
		bool first = true;
		REP(i, (N+1)/2) {
			if(!first)cout<<" ";
			cout<<"0";
			if(first) first=false;
		}
		REP(i, N/2) cout << " 100";
	}
	if(modus && mean){
		cout << "0";
		REP(i, N-1) cout << " " << 100-i;
	}
	if(modus && median){
		cout << "99";
		REP(i, (N+2)/3) cout << " 0";
		REP(i, (N-3)/3) cout << " 99";
		REP(i, (N+1)/3) cout << " 100";
	}

	cout << endl;
	return 0;
}
