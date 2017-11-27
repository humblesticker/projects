#include <string>
#include <iostream>
using namespace std;

class BuffaloBuffalo {
  bool check(string s, string word) {
    int wlen = word.length(), slen = s.length();
    for(int i=0; i<slen; i+=wlen)
      if(s.substr(i, wlen) != word) return false;
    return true;
  }

public:
  string check(string s) {
    return check(s + " ", "buffalo ") ? "Good" : "Not good";
  }
};
