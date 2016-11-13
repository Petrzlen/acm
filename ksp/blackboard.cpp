#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    LLI n,k,r;
    cin >> n >> k >> r;
    
    if(k==1){
      cout << ((r-1)%n)+1 << endl;
      continue;
    }
    
    LLI len=k;
    LLI a=0;
    LLI b=n; //<a,b) cyclic
    LLI ra=0;
    LLI rb=n;
    
    while(r > 0 && a != b){
      //cout << "a="<<a << " b="<<b<< " r="<<r<< " len="<<len << endl;
      
      if((b-a)/len >= r){
        ra=a+len*(r-1)+1; 
        rb=a+len*r+1; 
        break;
      }/*
      if((b-a)/len < k){
        ra=1;
        rb=n+1;
        break;
      }*/
      r -= (b-a)/len; 
      LLI m=(b-a)%len;
      
      if(m!=0){
        LLI d=m/(len/k); //!bezo zvysku
        b -= m;
        a += len*(k-d); 
        
        //cout << "a="<<a << " b="<<b<< " r="<<r<< " len="<<len << " d="<<d << endl;
        
        if(a>=b){
          ra=1;
          rb=n+1;
          break;
        }
        if(r <= 1){
          ra=b+1;
          rb=a+1;
          break;
        }
        r--;
      }
      
      len *= k; 
    }
    //cout << "ra="<<ra << " rb="<<rb << endl;
    if(ra<rb) cout << (rb-ra)*(rb+ra-1)/2 << endl;
    else cout << n*(n+1)/2 - (ra-rb)*(ra+rb-1)/2 << endl;
    
    //cout << "----" << endl;
  }
	return 0;
}
