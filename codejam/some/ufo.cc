#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)
#define EPS 0.0000001

double bs(double from, double to, double target) {
  double mid = (to + from) / 2.0;
  if (to - from < EPS) return mid;

  double value = sin(mid) + cos(mid);
	if (value < target) return bs(mid, to, target);
	return bs(from, mid, target);
}

double solve() {
  double target;
	cin >> target;
	return bs(0, M_PI/2.0, target);
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
	  double r = solve();
		printf("Case #%d:\n", t+1); 
		printf("%.8f %.8f %.8f\n", cos(r)/2.0, -sin(r)/2.0, 0.0);
		printf("%.8f %.8f %.8f\n", sin(r)/2.0, cos(r)/2.0, 0.0);
		printf("%.8f %.8f %.8f\n", 0.0, 0.0, 0.5);
  }
  return 0;
}
