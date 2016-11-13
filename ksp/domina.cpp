#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef pair<int, int> PII;

int main()
{
  multiset<PII> S;
  int n, q;
  cin >> n >> q;
  REP(i, n){
    int a, b;
    cin >> a >> b;
    S.insert(PII(a,b));
    if(a != b) S.insert(PII(b,a));
  }
  REP(i, q){
    long long int result = 0;
    int c;
    cin >> c;
    for(multiset<PII>::iterator diter = S.begin(); diter != S.end(); diter++){
      PII d = *diter; 
      PII f(d.first, c-d.second); //label, target cena
      //cout << "("<<d.first<<","<<d.second<<") & ("<<f.first<<","<<f.second<<") " << S.count(f) << endl;
      result += S.count(f);
      result -= d == f; 
    }
    cout << result/2 << endl;
  }
  
	return 0;
}
