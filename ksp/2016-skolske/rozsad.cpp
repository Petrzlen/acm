#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <queue> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;
typedef pair<int, int> PII; 

int N; 
int f(int p){
  if(p<0) return 0;
  if(p>=N-1) return N-1;
  return p;
}
int mojmin(int a,int b) {return (a<b)?a:b;}
int mojmax(int a,int b) {return (a>b)?a:b;}

int main()
{
  //zac, kon, id
  vector<pair<PII, int> > I;
  cin >> N;
  
  int F[N];
  REP(i, N) F[i]=-1; 
  REP(i, 2*N) {
    int v;
    cin >> v;
    v--;
    if(F[v]==-1) {
      F[v]=i;
      continue;
    }
    //koniec, zaciatok, id
    int kon = f(i-N);
    int zac = f(F[v]);   
    I.push_back(pair<PII, int>(PII(mojmin(zac, kon), mojmax(zac,kon)), v+1)); 
  }  
  
  sort(I.begin(), I.end()); 
  
  /*
  REP(i, N) {
    cout << I[i].first.first << ","<< I[i].first.second << "|" << I[i].second << endl;
  }*/
  
  //kon pos, id
  priority_queue<PII> PQ;  
  int R[N];
  int ii=0;
  for(int ri=0; ri < N; ri++) {
    while(ii < N && I[ii].first.first <= ri){
      PQ.push(PII(-I[ii].first.second, I[ii].second)); 
      //cout << "push: " << PQ.top().first << "|" << PQ.top().second << endl; 
      ii++; 
    }
    R[ri] = PQ.top().second;
    PQ.pop();
  }
  REP(i, N) cout << R[i] << " ";
  REP(i, N) {
    if(i != 0) cout << " ";
    cout << R[i];
  }
  cout << endl;  

	return 0;
}
