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

#define INF 1987654321

#define MAX (1 << 20)
vector<int> A(2*MAX, INF);
vector<int> B(2*MAX, INF); 

void build(vector<int>& T, int n=1){
  if(n >= MAX) return; 

  build(T, n*2);
  build(T, n*2+1); 
  T[n] = min(T[n*2], T[n*2+1]); 
} 

int get(vector<int>& T, int from, int to, int n=1, int a=0, int b=MAX){
  //cout << "  n=" << n << " a=" << a << " b=" << b << endl;
  
  if(to <= a || b <= from || from >= to) return INF; 
  if(from <= a && b <= to) {
    //cout << "  ret " << T[n] << endl; 
    return T[n]; 
  }
  
  int m = (a + b) / 2; 
  return min(
    get(T, from, min(m, to), n*2, a, m), 
    get(T, max(m, from), to, n*2+1, m, b)
  ); 
}

void test(vector<int>& T, int f, int t){
  cout << "test ("<<f<< ", " << t << "): " << get(T, f, t) << endl;
}

int main(){
  string bullshit, s; 
  cin >> bullshit >> s; 
  
  A[MAX+0] = 0; 
  REP(i, s.size()) A[MAX+i+1] = A[MAX+i] + ((s[i] == 'p') ? 1 : -1); 
  build(A); 
  
  B[MAX+s.size()] = 0; 
  REP(i, s.size()) B[MAX+s.size()-i-1] = A[MAX+s.size()-i] + ((s[s.size()-i] == 'p') ? 1 : -1); 
  build(B); 
 
  
 
 /*
  cout << "A" << endl;
  REP(i, s.size()+1) cout << " " << A[MAX+i]; cout << endl;
  test(A, 1, 5); 
  test(A, 2, 5); 
  test(A, 3, 5);
  test(A, 4, 5); 
  test(A, 5, 5);  
  
  cout << "B" << endl; 
  REP(i, s.size()+1) cout << " " << B[MAX+i]; cout << endl;
  test(B, 1, 5); 
  test(B, 2, 5); 
  test(B, 3, 5);
  test(B, 4, 5); 
  test(B, 5, 5);  */ 
  
  return 0; 
}
