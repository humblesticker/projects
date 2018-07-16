#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int i = s.length()-1, j = t.length()-1;
    while(i >= 0 && j >= 0) {
        if(s[i] != t[j]) break;
        i--; j--;
    }
    cout << i + j + 2 << "\n";
    return 0;
}