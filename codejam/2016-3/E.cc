#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

string S;
#define MAX 21212
int B[MAX][MAX];

int profit(int i, int j) { return 5*(1+(S[i]==S[j])); }

int best(int N, int a, int b) {
  if (b <= a) return 0;
  if (B[a][b]>0) return B[a][b];
  // B[a][b] = max(profit(a,b-1)+best(N,a+1,b-1), profit(a,a+1)+best(N,a+2,b));
  for (int i=b; i>a; i-=2) {
    
    B[a][b]=max(B[a][b],profit(a,i-1)+best(N,a+1,i-1)+best(N,i,b));
  }
  return B[a][b];
}

int best_old(int N, int a, int b) {
//  cout << N << " " << a << " " << b << endl;
  if (b <= a) return 0;
  if (B[a][b]>0) return B[a][b];
  int m=0;
  // Divide
  for(int i=a+2; i<b; i+=2) m=max(m,best(N,a,i)+best(N,i,b));
  // All all together
  int s=0;
  for(int i=a;i<((a+b)/2);i++) {
    s+=5*(1+(S[i]==S[b-1-(i-a)]));
  }
//  cout << a << " " << b << " " << m << " " << s << endl;
  B[a][b]=max(m, s);

}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    cin >> S;
    int N=S.size();
    int p=0,n=0;
    REP(i, N/2) p+=S[i*2]=='C';
    REP(i, N/2) n+=S[i*2+1]=='C';
    int match = min(p,n)+min(N/2-p,N/2-n);
    cout << 10*match + 5*(N/2-match) << endl;
//    REP(i,N+1)REP(j,N+1)B[i][j]=0;

//    cout << best(N,0,N) << endl;
  }
  return 0;
}
