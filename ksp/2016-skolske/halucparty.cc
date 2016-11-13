#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define REP(i, to) for (int i = 0; i < to; ++i)

typedef long long int LLI;

struct Point {
  LLI x;
  LLI y;
  LLI dx;
  LLI dy;
};
vector<Point> orig;

bool CmpByX(int a, int b) {
  return (orig[a].x != orig[b].x) ? orig[a].x < orig[b].x : orig[a].y < orig[b].y;
}

bool CmpByY(int a, int b) {
  return (orig[a].y < orig[b].y);
}

int main() {
  int R;
  cin >> R;
  vector<int> byx;
  vector<int> byy;
  REP(i, R) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int x=x1; x<=x2; ++x) for (int y=y1; y<=y2; ++y) {
      Point p;
      p.x = x;
      p.y = y;
      p.dx = 0;
      p.dy = 0;
      byx.push_back(orig.size());
      byy.push_back(orig.size());
      orig.push_back(p);
    }
  }
  sort(byx.begin(), byx.end(), CmpByX);
  sort(byy.begin(), byy.end(), CmpByY);

  LLI d=0;
  for (LLI i = 1; i < byx.size() ; ++i) {
    d += i * (orig[byx[i]].x - orig[byx[i-1]].x);
  //  cout << i << " " << d << " " << orig[byx[i]].x << endl;
    orig[byx[i]].dx += d;
  }
  d=0;
  for (LLI i = byx.size() - 2; i >= 0 ; --i) {
    d += (byx.size() - i - 1) * (orig[byx[i+1]].x - orig[byx[i]].x);
  //  cout << i << " " << d << " " << orig[byx[i]].x << endl;
    orig[byx[i]].dx += d;
  }
  d=0;
  for (LLI i = 1; i < byy.size() ; ++i) {
    d += i * (orig[byy[i]].y - orig[byy[i-1]].y);
  //  cout << i << " " << d << " " << orig[byy[i]].y << endl;
    orig[byy[i]].dy += d;
  }
  d=0;
  for (LLI i = byy.size() - 2; i >= 0 ; --i) {
    d += (byy.size() - i - 1) * (orig[byy[i+1]].y - orig[byy[i]].y);
  //  cout << i << " " << d << " " << orig[byy[i]].y << endl;
    orig[byy[i]].dy += d;
  }

  LLI bestd=987654321987654321;
  int resi = 0;
  REP(i, byx.size()) {
    LLI can = orig[byx[i]].dx + orig[byx[i]].dy;
  //  cout << orig[i].x << " " << orig[i].y << " " << can << endl;
    if (can < bestd) {
      resi = i;
      bestd = can;
    }
  }
  cout << bestd << endl << orig[byx[resi]].x << " " << orig[byx[resi]].y << endl;

  return 0;
}
