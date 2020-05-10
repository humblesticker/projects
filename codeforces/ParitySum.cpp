#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ParitySum {
    bool check(int n, int k, int base) {
        int r = n - (k - 1) * base;
        if(r <= 0) return false;
        return r % 2 == base % 2;
    }

    void print(int n, int k, int base) {
        cout << "YES" << endl;
        for(int i=0; i<k-1; i++) cout << base << ' ';
        cout << n - (k - 1) * base << endl;
    }
public:
    void sum(int n, int k) {
        if(n % 2 == 0) {
            if(k % 2 == 0) {
                if(check(n, k, 1)) return print(n, k, 1);
                if(check(n, k, 2)) return print(n, k, 2);
            } else {
                if(check(n, k, 2)) return print(n, k, 2);
            }
        } else {
            if(k % 2 == 1) 
                if(check(n, k, 1)) return print(n, k, 1);
        }

        cout << "NO" << endl;
    }
};

int main() {
    int t, n, k; ParitySum C;
    cin >> t;
    while(t-- > 0) {
        cin >> n >> k;
        C.sum(n, k);
    }
    return 0;
}
/*
use k - 1 of 1 or 2 and get remainder

r = n - (k - 1) * base 
if r <= 0 return NO
r shoud be the same parity

if n is even 
    if k is even use 1 and 2
    else use 2
else
    if k is odd use 1
    else NO
*/