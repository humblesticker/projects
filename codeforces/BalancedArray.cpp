#include <iostream>
using namespace std;

class BalancedArray {
public:
    void print(int n) {
        int m = n/2; if(m%2 != 0) { cout << "NO" << endl; return; }

        cout << "YES" << endl;
        for(int i=1; i<=m; i++) cout << 2*i << " ";
        for(int i=1; i<m; i++) cout << 2*i - 1 << " ";
        cout << 3*m - 1 << endl;
    }
};

int main() {
    int t, n; BalancedArray C;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        C.print(n);
    }
    return 0;
}