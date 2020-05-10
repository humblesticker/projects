#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class SumRoundNumber {
public:
    int sum(int n, vector<int>& nums) {
        int factor = 1, count = 0, d = 0;
        while(n > 0) {
            d = n % 10;
            if(d > 0) {
                nums.push_back(d * factor);
                count++;
            }
            n /= 10; factor *= 10;
        }
        return count;
    }
};

int main() {
    int t, n; SumRoundNumber C;
    vector<int> nums;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        cout << C.sum(n, nums) << endl;
        for (auto const &i: nums) cout << i << ' ';
        cout << endl;
        nums.clear();
    }
    return 0;
}
/*
f = 1

while n > 0
    d = n%10



    n = n/10, f = f*10

*/