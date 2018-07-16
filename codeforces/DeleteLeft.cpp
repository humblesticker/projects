#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int i = 0, slen = s.length(), tlen = t.length(), len = min(slen, tlen);
    for(; i<len; i++) 
        if(s[slen-1-i] != t[tlen-1-i]) break;
    cout << slen + tlen - 2 * i << "\n";
    return 0;
}
/*
int count = 0
iterate from back to shorter string len
    if not same break
    count++
return slen + tlen - 2 * count

*/
