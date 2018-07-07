#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Binary {
    vector<string> bin = { "0", "1" };
    
public:
    string build(int a, int b, int x) {
        int c = a >= b ? 0 : 1;
        vector<int> count = { a, b };
        string s = "";

        while(x-- > 0) {
            s += bin[c];
            count[c]--;
            c = (c + 1)%2;
        }

        c = (c + 1)%2;
        while(count[c] > 0) { s += bin[c]; count[c]--; }
        
        c = (c + 1)%2;
        while(count[c] > 0) { s += bin[c]; count[c]--; }

        return s;
    }
};

int main() {
    int a, b, x; Binary B;
    cin >> a >> b >> x;
    cout << B.build(a, b, x) << endl;
    return 0;
}
/*
3, 3, 1
*/