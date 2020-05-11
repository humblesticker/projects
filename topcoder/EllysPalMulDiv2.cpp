#include <string>
using namespace std;

class EllysPalMulDiv2 {
  bool palindrom(int n) {
    string s = to_string(n);
    int i = 0, j = s.size();
    while(i < j) if(s[i] != s[j]) return false;
    return true;
  }

public:
  int getMin(int x) {
  	for(int i=0, cur = x; i<1000; i++, cur += x) 
      if(palindrom(cur)) return cur;
    return -1;
  }
};
/*

*/
