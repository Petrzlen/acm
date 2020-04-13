// TESTED:
// g++ -std=c++14 blob-search.cc
// ./a.out 
// Basic Tests average read_count 71
// Average read_count 7
// Average read_count 100
// Average read_count 85
// # NO ERRORS

/*
A Blob is a shape in two-dimensional integer coordinate space where all cells have at least one
adjoining cell to the right, left, top, or bottom that is also occupied. Given a 10x10 array of
boolean values that represents a Blob uniformly selected at random from the set of all possible
Blobs that could occupy that array, write a program that will determine the Blob boundaries.
Optimize first for finding the correct result, second for performing a minimum number of cell
Boolean value reads, and third for the elegance and clarity of the solution.
Sample input:
0000000000
0011100000
0011111000
0010001000
0011111000
0000101000
0000101000
0000111000
0000000000
0000000000
Sample output:
Cell Reads: 44
Top: 1
Left: 2
Bottom: 7
Right: 6

*/

// Assuming "1" can be on the edge, i.e. with coordinate 0 or 9
// What you mean by "boundary"?
// Example says it's only Top-most, Left-most, Right-most, Bottom-most coord.
// That's what I implemented, but was also thinking if we need the full boundary
//
// == First thoughts:
// for i in [0,10)
//   for j in [0, 10)
//     // set minx, maxx, miny, maxy.
//
// // Find any blob point
// start = null
// for i in [0,10):
//   for j in [0,10):
//     if M[i][j]:
//       start = Point(i, j)
//       break
//   if start
//     break
// // Get the full shape.
// DepthFirstSearch(i, j)
// => Maybe better search with empty cells and start top-left and bottom right.
//
// == Second thoughts
// [0] How one generates an uniformly random blob?
//     (Not needed to implement, but gives insight).
// Just taking a random 100-bit number and taking a random sub-blob?
// -> That has a strong bias to small blobs.
// Generating from toppest, and then leftmost?
// -> But then what's the probability to grow it?
// TODO
//
// [1] What's the expected blob size?
// There are:
// 1 of size 0, 
// 100 of size 1, 
// 180 of size 2, 
// O((2 + 8) * 100) of size 3
//   (8 "L" shaped, 2 "I" shaped, with O(100) starting positions)
// 1 of size 100,
// 100 of size 1,
// 100*99/2 - 4 of size 2 (two holes anywhere but (0,1), (1,0)
// O(100^3) of size 3 (the hole anywhere but to cut of an 1 or 2 edge positions.
//
// ***Intuitevely, blob size around 75 +- 10 with confidence 99%***
//
// This can be reinforced by the fact, that
//   For growing N 1,2,... there are O(100) * O(4^N / symmetries) possible starts * shapes.
//   While for decreasing N 99,98,... there are O(100^(100-N) - invalid blobs).
// Hm, the "sample" from the problem now feels unlikely :)
//
// [2] Lets hack up a "random" blob generator.
// => With size average size ~75, the most likely answer is (0, 0, 9, 9)
// Also if "cut" the board into half, then it's almost guaranteed I hit a "1".
//
// Ok, thinking too much.
// Lets first explore the diagonals for "good enough" initial bounding boxes.
// And then verify if the whole blob fix into them.

#include "blob-search_test.h"

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <random>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define SIZE 10

typedef pair<int, int> Point;
struct Result {
 int top;
 int bottom;
 int left;
 int right;
 bool operator==(const Result& other) {
   if (other.top != top) return false;
   if (other.bottom != bottom) return false;
   if (other.left != left) return false;
   if (other.right != right) return false;
	 return true;
 }
 void PrintResult() {
   cout << "top=" << top << " left=" << left << " bottom=" << bottom
	      << " right=" << right;
 }
};

void PrintBoard(const vector<vector<bool>>& board) {
	int blob_size = 0;
	for (int i = 0; i < board.size(); ++i) {
	  for (int j = 0; j < board[i].size(); ++j) {
		  blob_size += board[i][j];
		  cout << (board[i][j] ? '1' : '0');
		}
		cout << endl;
	}
	cout << "Blob size: " << blob_size << endl;
}

// Chose an uniformly random starting point and iteratively
// generate neighbors with decreasing probability of being part of the blob.
// TODO: Not truly uniform, e.g. with 1/(100/4 * (1/(1-PROB_DECAY))^2)
//       it generates blob of size one in corner.
// TODO: Refactor with DFSHelper.
void GenerateBlob(vector<vector<bool>>& board, double prob_decay) {
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dist(0,1);
  vector<Point> deltas = {{0,1},{0,-1},{1,0},{-1,0}};

  queue<Point> to_generate;
  to_generate.push(Point(gen() % SIZE, gen() % SIZE));
  // SIZE x SIZE of falses.
  vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
	// Blob has to be size of at least one.
  double prob = 1.0;
  while(!to_generate.empty()) {
    Point p = to_generate.front();
    to_generate.pop();
    if (p.first < 0 || p.first >= SIZE ||
        p.second < 0 || p.second >= SIZE) continue;

		// If decision about this cell was already made, skip it.
    if (visited[p.first][p.second]) continue;
    visited[p.first][p.second] = true;

		// Make decision about the cell.
    if (dist(gen) > prob) continue;

    board[p.first][p.second] = true;
		// TODO: We can argue we should decay with each decision, not only
		// when a new blob part was generated (intuitively should increase variance)
    prob *= prob_decay;
		
		// Recursively decide on neigbors.
    for (Point delta : deltas) {
      to_generate.push(
          Point(p.first + delta.first, p.second + delta.second));
    }
  }
}

// Simulates read accesses to the board and counts #reads.
class Simulator {
 public:
  Simulator(vector<vector<bool>> board) : board_(board) {}
	bool Get(int i, int j) {
	  // TODO: Consider throwing a warning when algorithm reads the same cell.
		Point p(i, j);
		visited_.insert(p);
		stack_trace_.push_back(p);
		return board_[i][j];
	}
	size_t Count() const { return visited_.size(); }
	void PrintStackTrace() const {
	  for (Point p : stack_trace_) {
		  cout << p.first << " " << p.second << endl;
		}
	}
 private:
  vector<Point> stack_trace_;
	// TODO: Fix the algorithms properly, this of lazyness of adding a visited
	// cache to the algorithm itself.
	set<Point> visited_;
  vector<vector<bool>> board_;
};

Result DummyAlgo(const vector<vector<bool>>& board) {
  Result result;
	result.top = board.size();
	result.left = board.size();
	result.right = -1;
	result.bottom = -1;
	for (int i = 0; i < board.size(); ++i) {
	  for (int j = 0; j < board.size(); ++j) {
		  if (board[i][j]) {
			  result.top = min(result.top, i);
			  result.bottom = max(result.bottom, i);
			  result.left = min(result.left, j);
			  result.right = max(result.right, j);
			}
		}
	}
	return result;
}

// Find the top boundary by dummy finding the first point.
// Then do the same.
Result ImprovedDummy(Simulator* simulator) {
  assert(simulator->Count() == 0);

	Result result;
	result.top = SIZE;
  // Finding top.
	for (int i = 0; i < SIZE; ++i) {
	  // TODO: Might be more probable to start from middle out, i.e. 5,4,6,3,7,...
		// i.e. in general: SIZE / 2 + ((i == 0) ? -1 : 1) * i / 2;
	  for (int j = 0; j < SIZE; ++j) {
		  if (simulator->Get(i, j)) {
			  result.top = i;
				break;
			}
		}
  	if (result.top != SIZE) break;
	}

//  // ** This does NOT work. **
//  // TODO: Fix it with some path finding algorithm.
//  // The example non-working case is:
//  // 00000
//  // 1101 <- top 
//  // 01110
//  // 00110
//	// Now finding left by only going down and left. We already know that both
//	// (top - (1, 0)) and (top - (0, 1)) are zeros.
//	Point p(top.first + 1, top.second - 1);
//	Point left = top;
//	while (p.first < SIZE && p.second >= 0) {
//	  if (simulator->Get(p.first, p.second)) {
//		  left = p;
//			p.second -= 1;
//		} else {
//		  p.first += 1;
//		}
//	}

  // Finding left. Note the loop ordering of "j" and "i" is switched.
	result.left = SIZE;
	for (int j = 0; j < SIZE; ++j) {
	  // We already read all cells in rows [0, top.first)
		// Note we still might read the same cell again, but Simulator counts
		// only number of distinct reads.
	  for (int i = result.top; i < SIZE; ++i) {
		  if (simulator->Get(i, j)) {
			  result.left = j;
				break;
			}
		}
  	if (result.left != SIZE) break;
	}

	result.right = -1;
	for (int j = SIZE - 1; j > result.left; --j) {
	  for (int i = result.top; i < SIZE; ++i) {
		  if (simulator->Get(i, j)) {
			  result.right = j;
				break;
			}
		}
  	if (result.right != -1) break;
	}
	// Note we had "j > result.left", so if we didn't find a blob piece
	// in columns [result.left + 1, SIZE), the right boundary must be result.left.
	// Currently that optimization doesn't save us any reads, as Simulator
	// counts unique accessess and we traverse the column in the same order.
	// But good to have it.
	if (result.right == -1) result.right = result.left;

	result.bottom = -1;
	for (int i = SIZE - 1; i > result.top; --i) {
	  for (int j = result.left; j <= result.right; ++j) {
		  if (simulator->Get(i, j)) {
			  result.bottom = i;
				break;
			}
		}
  	if (result.bottom != -1) break;
	}
	// Same reasoning as above.
	if (result.bottom == -1) result.bottom = result.top;

	return result;
}

bool UnitTest(const vector<vector<bool>>& board, int* read_count) {
  assert(read_count != nullptr);
	Result dummy = DummyAlgo(board);
	Simulator simulator(board);
	Result improved = ImprovedDummy(&simulator);
	*read_count = simulator.Count();
	if (dummy == improved) {
//		cout << "Wop wop board solved. Read count " << simulator.Count() << endl;
		return true;
	} 
	cout << "Stack trace:" << endl;
	simulator.PrintStackTrace();
	cout << endl << "Board:" << endl;
	PrintBoard(board);
	cout << endl << "Yikes! Given:";
	improved.PrintResult();
	cout << endl << "Expected:";
	dummy.PrintResult();
	cout << endl;
  return false;
}

typedef double ProbabilityDecay;
int main() {
  // Lets do a lot of testing, as that's the primary objective of this
	// exercise.
	long long int basic_tests_total_read_count = 0;
	int basic_tests_read_count = 0;
  for (const auto& test_board_strs : TEST_BOARDS) {
	  const auto& board = StringToBoard(test_board_strs);
		if (!UnitTest(board, &basic_tests_read_count)) {
		  cerr << "Algorithm failed even the basic test case, abort." << endl;
		  return 0;
		}
		basic_tests_total_read_count += basic_tests_read_count;
	}
	cout << "Basic Tests average read_count "
	     << basic_tests_total_read_count / TEST_BOARDS.size() << endl;

  // Now UnitTest on generated blobs.
	// TODO: Add other generative algorithms.
  const int GEN_TEST_CASES = 1000;
	vector<ProbabilityDecay> prob_decays = {
      // Empirically determined to give blob_size ~75
      0.994,
			// For small blobs:
			0.1,
			// For medium blobs
			0.9
	};
	for (ProbabilityDecay prob_decay : prob_decays) {
	  long long int total_read_count = 0;
		int read_count = 0;
		for (int t = 0 ; t <= GEN_TEST_CASES; ++t) {
			vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false));
			GenerateBlob(board, prob_decay);
			UnitTest(board, &read_count);
			total_read_count += read_count;
		}
		cout << "Average read_count " << total_read_count / GEN_TEST_CASES << endl;
	}
  return 0;
}

Result MaybeABetterSolution(Simulator& simulator) {
	// In each step, we explore (read) one cell.
	// First find "good enough" initial bounding box by traversing the diagonals.
	// If not found any (max blob size 20), fall back to bruteforce (simple).
	//   If found, then bound the blob. E.g. for the topmost boundary,
	//   take the right-most zero at result.top - 1 and go right.
	//     If it's a one, explore top. If it's a zero, repeat.
	//     then take the left-most zero at result.top - 1 and go left.
	//   Similarly for right, left, bottom. We do this in round-robin
	//   fashion, as the boundaries will reach to each other.
	//   To verify it's correct, we run DFS from a one, and verify that zeros
	//   and the board boundary covers bounds it.
	// Oh, too complicated. Let's just do the DFS from two corners.
}

// Thoughts on "If we need the full boundary, not just Left,Right,Top,Bottom"
//   [1b] Which cell has the biggest likelihood of:
//        being an empty cell, next to a blob (call it "empty boundary")?
//   Unsure
// [2] After finding the boundary, how we search around?
//   We can leverage the "battle-ship finding" (BsF) algorithm.
//   E.g. when we know that (0,1) and (1,0) are "water", then (0,0) is (most likely) a water too.
//   Ideally, we would like to have a 10x10 likelihood map if a cell is part of a blob,
//   given the cells read. But that still doesn't solve which cell to search next.
//
// Oh, overthinking, lets just do a basic diagonal BsF,
// e.g. starting (0,2), (1,1), (2,0), if all empty move to (4,0), (3,1)
// and after hit, try up (in general neighbor cell closest to board edge)
