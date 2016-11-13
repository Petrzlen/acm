#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int N;
  vector<int> sum(2,0); 
  char last='A', c; 
  
  scanf("%d\n", &N);
  REP(i, N-1){
    scanf("%c", &c);
    sum[c!='C']++;
    last=c;
  }
  if(last=='A') cout << "rovnako" <<endl;
  else cout << (((2*sum[0]-(last=='C')) > (2*sum[1]-(last!='C'))) ? "caj" : "mlieko")<< endl;
  
  /*
  vector<int> sum_caj(N+1,0), sum_mlieko(N+1,0); 
  
  REP(i, N-1){
    char c;
    scanf("%c", &c);
    if(c=='C') {
      sum_caj[N-1-i]--;
      sum_caj[0]++;
    }
    else{
      sum_mlieko[N-1-i]--;
      sum_mlieko[0]++; 
    }
  }
  if(sum_caj == sum_mlieko) cout << "rovnako" << endl; 
  else cout << (sum_caj > sum_mlieko ? "caj" : "mlieko") << endl;
  
  REP(i, N) cout << sum_caj[i] << " ";
  cout << endl;
  REP(i, N) cout << sum_mlieko[i] << " "; */
  
	return 0;
}
