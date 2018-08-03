#include <string>
using namespace std;

int convert(string s) {
    int n = 0;
    for(char c : s) n = c - 'A' + 1 + n * 26;
    return n;
}

/*
A -> 1, 
AA -> 27
ZZ -> 702
*/