// TODO there must be an easier solution
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef long long int LLI;

#define FOR(i, to) for(int i = 0; i < to; i++)

bool solve() {
  int R, C, H, V;
	cin >> R >> C >> H >> V;

	bool M[R][C];
	int total = 0;
	FOR(i, R) {
	  string s;
	  cin >> s;
		FOR(j, C) {
		  M[i][j] = (s[j] == '@');
		  total += M[i][j];
		}
	}
	if (total == 0) return true;

	int pieces = (H+1) * (V+1);
  //cout << "total " << total << " pieces " << pieces << endl;
	if (total % pieces != 0) return false;

	int S[R+1][C+1];
	FOR(i, R+1) FOR(j, C+1) S[i][j] = 0;
	FOR(i, R) FOR(j, C) S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + M[i][j];

	// FOR(i, R+1) { FOR(j, C+1) //cout << S[i][j]; //cout << endl;}

  // every H split has to have the same amount of chocholate,
	// that way there is exactly one way to do it
  vector<int> H_splits;
  int per_row = total / (H + 1);
	int last_r = 0;
	FOR(i, R) {
	  int slice_count = S[i+1][C] - S[last_r][C];
		//cout << "slice_count " << slice_count << " last_r " << last_r << " i " << i << endl;
	  if (slice_count == per_row) {
		  H_splits.push_back(i+1);
			last_r = i+1;
			//cout << "slice " << last_r << endl;
		}
		if (H_splits.size() == H) break;
	}
	if (H_splits.size() != H) return false;

	// !! COPY PASTER !!
  vector<int> V_splits;
  int per_column = total / (V + 1);
	int last_c = 0;
	FOR(j, C) {
	  int slice_count = S[R][j+1] - S[R][last_c];
		//cout << "slice_count " << slice_count << " last_c " << last_c << " j " << j << endl;
	  if (slice_count == per_column) {
		  V_splits.push_back(j+1);
			last_c = j+1;
			//cout << "slice " << last_c << endl;
		}
		if (V_splits.size() == V) break;
	}
	if (V_splits.size() != V) return false;

  int per_cut = total / pieces;
  FOR(i, H) FOR(j, V) {
	  int expected = (i+1) * (j+1) * per_cut;
		int cut = S[H_splits[i]][V_splits[j]];
		//cout << i << " " << j << " exp: " << expected << " cut: " << cut << endl;
	  if (expected != cut) return false;
	}

	return true;
}

int main() {
  int T;
	cin >> T;
	FOR(t, T) {
		cout << "Case #" << t + 1 << ": " << (solve() ? "" : "IM") << "POSSIBLE" << endl;
  }
  return 0;
}
