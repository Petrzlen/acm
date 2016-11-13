#include <iostream>
#include <vector>
#include <cstdio> 
#include <string> 
#include <algorithm>

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI;

using namespace std;

char M[4][25][25] = {{
"     ",
" # # ",
"#####",
" ### ",
"  #  "},{
"  #  ",
" ### ",
"#####",
" ### ",
"  #  "},{
"  #  ",
" ### ",
"#####",
"# # #",
"  #  "},{
" ### ",
"  #  ",
"#####",
"# # #",
"  #  "}};

string V[15] = {"SENTINEL","SENTINEL","two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"}; 

char Vm[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};

string S[4] = {"hearts", "diamonds", "spades", "clubs" }; 

int C[12][2] = {
{3,10},
{9,10},
{15,10},
{21,10},
{3,2},
{9,2},
{15,2},
{21,2},
{3,18},
{9,18},
{15,18},
{21,18}
};

char R[30][25]; 

void copycard(int ci, int r, int c){
  REP(i, 5) REP(j, 5) R[r+i][c+j] = M[ci][i][j];
}

int main()
{
  REP(i, 30) REP(j, 25) R[i][j] = ' ';
  string v, s;
  cin >> v >> v;
  cin >> s >> s;
  int vi, si;
  REP(i, 15) if(V[i]==v) vi=i;
  REP(i, 4) if(S[i]==s) si=i;
  int pvi = (vi > 10) ? 1 : vi; 
  
  REP(i, 25) R[0][i] = R[29][i] = '-';
  REP(i, 30) R[i][0] = R[i][24] = '|';
  R[0][0] = R[0][24] = R[29][0] = R[29][24] = '+';
  
  R[1][1] = R[1][23] = R[28][1] = R[28][23] = Vm[vi];
  if(vi==10){
    R[1][1] = R[1][22] = R[28][1] = R[28][22] = '1';
    R[1][2] = R[1][23] = R[28][2] = R[28][23] = '0';
  } 
  
  if(pvi > 0 && pvi < 5) {
    REP(i, pvi) copycard(si, C[i][0], C[i][1]);  
  }
  if(pvi > 4 && pvi < 9) {
    int i=0;
    for( ; i+4 < pvi ; i++){
      copycard(si, C[i+4][0], C[i+4][1]);
      copycard(si, C[i+8][0], C[i+8][1]);
    }
    for( ; i < 4 ; i++) copycard(si, C[i][0], C[i][1]); 
  }
  if(pvi > 8 && pvi < 13) {
    int i=0;
    for( ; i+8 < pvi ; i++){
      copycard(si, C[i][0], C[i][1]); 
      copycard(si, C[i+4][0], C[i+4][1]);
      copycard(si, C[i+8][0], C[i+8][1]);
    }
    for( ; i < 4 ; i++) {
      copycard(si, C[i+4][0], C[i+4][1]);
      copycard(si, C[i+8][0], C[i+8][1]);
    } 
  }
  
  REP(i, 30) {REP(j, 25) cout << R[i][j]; cout << endl;}
   
	return 0;
}
