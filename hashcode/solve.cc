#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <chrono>
#include <queue>
#include <fstream> 
#include <time.h>

using namespace std;
bool debug = false;
int MAX_RUNS = 100000;
int run_time = 10;  // in secs

#define FOR(i, to) for(int i = 0; i < to; i++)
typedef pair<int, int> PII; 

int D;  // days
vector<int> B;  // book values
vector<int> Bf; // book frequencies
int sort_orders = 1;

class Library {
public:
	int s;  // signup
	int t;  // throughput
	int bi;  // current books[i]
	vector<int> books;
	vector<int> chosen;
	int val;

	void reset(int sort_order) {
		this->chosen.clear();
		this->bi = 0;

		if (sort_order == 0) {
			sort(books.begin(), books.end(), [](int b1, int b2) {
				return B[b1] > B[b2];
			});
		}
	}

	int tp_val() {
	  int real_t = (int)min(this->t, (int)this->books.size());
		return (this->val * real_t) / this->books.size();
	}

	bool done() {
		return this->bi >= this->books.size();
	}
};

vector<Library> L;  // libraries

void choose(int li, vector<int>& Bpicked) {
  Library* l = &L[li];
	// don't run the T loop if already done
	if (l->done()) return;

  FOR(t, l->t) {
		for (;l->bi < l->books.size(); l->bi++) {
		  int bi = l->books[l->bi];
			if (Bpicked[bi]) {
			  if (debug) cout << "lib " << li << "skip " << bi << endl;
				continue;
			}
			if (debug) cout << "lib " << li << " choose " << bi << " value " << B[bi] << endl;
			l->chosen.push_back(bi);
			Bpicked[bi] = true; 
		}
	}
}

// number chosen, total );value
PII run(vector<int>& Lorder, int sort_order) {
  if (debug) cout << "RUN " << Lorder.size() << endl;
	FOR(i, L.size()) L[i].reset(sort_order);

	vector<int> Bpicked(B.size(), false);
	vector<int> Lcurrent;
	int loi = 0;
	int li = Lorder[loi];
	int dsignup = L[li].s;
	FOR(d, D) {
	  if (debug) cout << "DAY " << d << " Lcurrent " << Lcurrent.size() << " dsignup " << dsignup << endl;
		FOR(lci, Lcurrent.size()) choose(Lcurrent[lci], Bpicked);
		// TODO(peter): Filter out already done guys.

	  // get "best" books
		if (d == dsignup) {
			if (debug) cout << "signed up " << li << endl; 
			Lcurrent.push_back(li);
			loi++;
			li = Lorder[loi];
			dsignup = d + L[li].s;
			if (debug) cout << "next sign  up " << li << " at " << dsignup << endl; 
		}
	}

	int res = 0;  // 10^4 * 10^5 should fit
	FOR(i, L.size()) {
	  int lib_res = 0;
		FOR(j, L[i].chosen.size()) {
			lib_res += B[L[i].chosen[j]];
		}
		if (debug) cout << "lib " << i << " choose " << L[i].chosen.size() << " valued " << lib_res << endl; 
		res += lib_res;
	}
	return PII(loi, res);
}

void print_libs(vector<int>& Lorder, int loi);  // declare

int main() {
	srand(time(NULL));
  auto start_t = chrono::steady_clock::now();

  int bsize, lsize;
	cin >> bsize >> lsize >> D;

	B = vector<int>(bsize, 0);
	FOR(i, bsize) cin >> B[i];
	FOR(i, lsize) {
		Library l;
		int lb;
	  cin >> lb >> l.s >> l.t;
		l.books = vector<int>(lb, 0);
		FOR(j, lb) cin >> l.books[j];
		l.val = 0;
		FOR(j, lb) l.val += B[l.books[j]];
		L.push_back(l);
		// cout << "lib " << i << " books " << l.books.size() << " top " << l.books[0] << " val " << B[l.books[0]] << endl;
		// cout << "  " << l.val << " " << l.tp_val() << endl;
	}

	int best = 0;
	auto Lorder = vector<int>(L.size(), 0);
	FOR(i, L.size()) Lorder[i] = i;
	FOR(ri, MAX_RUNS) {
		auto r = run(Lorder, 0);
	  // cout << "run " << ri << " " << r.first << " " << r.second << endl;
		if (r.second > best) {
			cout << "!found better! " << r.second << endl;
			best = r.second;
		  print_libs(Lorder, r.first);
		}

		// shuffle shit around
		random_shuffle(Lorder.begin(), Lorder.end());
		/* 
		sort(Lorder.begin(), Lorder.end(), [](int l1, int l2) {
		  int rsize = L[l1].tp_val() + L[l2].tp_val();
			int r1 = rand() % rsize;
			int r2 = rand() % rsize;
			// return L[l1].val > L[l2].val;
			return L[l1].tp_val() + r1 > L[l2].tp_val() + r2;
		}); */

		
		auto now_t = chrono::steady_clock::now();
		if (run_time < chrono::duration_cast<chrono::seconds>(now_t - start_t).count()) {
			cout << "time run up!" << endl;
			break;
		}
	}	

  return 0;
}

void print_libs(vector<int>& Lorder, int lo_size) {
  ofstream fout("solution.out");

  // some libs might end up we 0 chosen books, TODO: optimize
	int non_zero = 0;
	FOR(loi, lo_size) {
		int li = Lorder[loi];
		Library* l = &L[li];
		non_zero += l->chosen.size() != 0;
	}
	fout << non_zero << endl;

	FOR(loi, lo_size) {
		int li = Lorder[loi];
		Library* l = &L[li];
		if (l->chosen.size() == 0) continue;

		fout << li << " " << l->chosen.size() << endl;
		FOR(ci, l->chosen.size()) {
			if (ci != 0) fout << " ";
			fout << l->chosen[ci];
		}
		fout << endl;
	}
	fout.close();
}
