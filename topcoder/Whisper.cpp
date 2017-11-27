#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Whisper {
  bool starts(string s, string find) {
    int len = find.length();
    return s.length() >= len && s.substr(0, len) == find;
  }

public:
  string toWhom(vector<string> &names, string &typed) {
    transform(typed.begin(), typed.end(), typed.begin(), ::tolower);
    if(!starts(typed, "/msg ")) return "not a whisper";
    typed = typed.substr(5);

    int max = 0, index = -1;
    for(int i=0; i<names.size(); i++) {
      string name = names[i]; transform(name.begin(), name.end(), name.begin(), ::tolower);
      if(starts(typed, name + " ")) if(name.length() > max) { max = name.length(); index = i; }
    }

    return index >= 0 ? names[index] : "user is not logged in";
  }
};
