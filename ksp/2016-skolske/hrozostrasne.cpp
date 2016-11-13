#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int n;
  char *s;
  size_t nbytes = 256;
  
  scanf("%d\n", &n);
  REP(i, n){
    int s_size = getline(&s, &nbytes, stdin); 
    double vowel=0; 
    double count=0;
    
    REP(j, s_size){
      if(isalpha(s[j])) count++; 
      if('a' == tolower(s[j]) || 'e' == tolower(s[j]) || 'i' == tolower(s[j]) || 'o' == tolower(s[j]) || 'u' == tolower(s[j]) || 'y' == tolower(s[j])) vowel++; 
    }
    
    printf("%.12f\n", (vowel/count)*100.0);
  }
  
	return 0;
}
