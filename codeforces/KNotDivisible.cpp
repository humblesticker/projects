#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class KNotDivisible {
    
public:
    // binary search 
    int find(int n, int k) {
        int factor = k / (n-1);
        int d = n * factor - 1, pos = (n - 1) * factor;
        while(pos < k) {
            d++; if(d % n != 0) pos++;
        }
        return d;
    }
};

int main() {
    int t, n, k; KNotDivisible C;
    cin >> t;
    while(t-- > 0) {
        cin >> n >> k;
        cout << C.find(n, k) << endl;
    }
    return 0;
}