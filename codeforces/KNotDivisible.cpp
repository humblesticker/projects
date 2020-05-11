#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class KNotDivisible {
public:
    // binary search
    int find(int n, int k) {
        int factor = k/(n - 1), i = n * factor, j = n * (factor + 1);
        int mid = 0, pos = 0;

        while(i <= j) {
            mid = i + (j-i)/2;
            pos = mid - mid/n;

            if(pos < k) i = mid + 1;
            else if(pos > k) j = mid - 1;
            else return mid % n == 0 ? mid - 1 : mid;
        }

        return -1;
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