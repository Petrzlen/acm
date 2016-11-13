#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

#define REP(i, to) for (int i = 0; i < to; ++i)

string B[] = {
"1",
"11",
"121",
"12321",
"1234321",
"123454321",
"12345654321",
"1234567654321",
"123456787654321",
"12345678987654321",
"1234567900987654321",
"123456790120987654321",
"12345679012320987654321",
"1234567901234320987654321",
"123456790123454320987654321",
"12345679012345654320987654321",
"1234567901234567654320987654321",
"123456790123456787654320987654321",
"12345679012345678987654320987654321",
"1234567901234567900987654320987654321",
"123456790123456790120987654320987654321",
"12345679012345679012320987654320987654321",
"1234567901234567901234320987654320987654321",
"123456790123456790123454320987654320987654321"
};
#define B_SIZE 24

string T[] = {
  "12345679012345679012345679012345679012345679012345654320987654320987654320987654320987654320987654321",
  "1234567901234567901234567901234567901234567901234567654320987654320987654320987654320987654320987654321",
  "123456790123456790123456790123456790123456790123456787654320987654320987654320987654320987654320987654321",
  "12345679012345679012345679012345679012345679012345678987654320987654320987654320987654320987654320987654321",
  "1234567901234567901234567901234567901234567901234567900987654320987654320987654320987654320987654320987654321",
  "123456790123456790123456790123456790123456790123456790120987654320987654320987654320987654320987654320987654321",
  "12345679012345679012345679012345679012345679012345679012320987654320987654320987654320987654320987654320987654321",
  "1234567901234567901234567901234567901234567901234567901234320987654320987654320987654320987654320987654320987654321",
  "123456790123456790123456790123456790123456790123456790123454320987654320987654320987654320987654320987654320987654321",
  "1234567901234567901234567901234567901234567901234567901234567900987654320987654320987654320987654320987654320987654320987654321"
};
#define T_SIZE 10

string solve(int n, int a, int b) {
  vector<string> M(9, "");
  REP(i, B_SIZE) M[i%9] = B[i];
  string R1 = "123456790";
  string R2 = "987654320";

  string m = M[n%9];
  int l = 2*n - 1;
  int m1 = (l - m.size())/2;
  int m2 = m1 + m.size();
//  cout << m1 << " " << m2 << " " << l << endl;
  string res;
  for (int i = a-1; i < b && i < m1; ++i) res += R1[i%9];
  for (int i = max(m1,a-1); i < b && i < m2; ++i) res += ((i+1==m2) ? '0' : M[n%9][i-m1]);
  for (int i = max(m2,a-1); i < b; ++i) res += ((i+1==l) ? '1' : R2[(i-m2)%9]);

  return res;
}

void test() {
  REP(t, T_SIZE) {
    int n = (T[t].size() + 1) / 2;
    for (int a=1; a<=T[t].size(); ++a) REP(b,T[t].size()+1)  if (b >= a) {
      string s = solve(n, a, b);
      string e = T[t].substr(a-1, b-a+1);
      if (s != e) {
        cout << n << " " << a << " " << b << endl;
        cout << s << endl << e << endl;
        return;
      }
    }
  }
}

int main() {
  test();

  int n, a, b;
  cin >> n >> a >> b;
  if (n <= B_SIZE) cout << B[n].substr(a-1, b-a+1) << endl;
  else {
    cout << solve(n, a, b) << endl;
  }
  
  return 0;
}