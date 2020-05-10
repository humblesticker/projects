#include <iostream>
#include <vector>
using namespace std;

class Candies {
    vector<int> factors;

public:
    Candies() {
        int factor = 2; 
        factors.resize(30); 
        for(int i=0; i<factors.size(); i++, factor *= 2) factors[i] = factor;
    }

    int find(int n) {
        for(int i=1; i<factors.size(); i++)  // k > 1 
            if(n % (factors[i] - 1) == 0) return n/(factors[i] - 1);
        return -1; // should not hit this, throw exception?
    }
};

int main() {
    int t, n; Candies C;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        cout << C.find(n) << endl;
    }
    return 0;
}
/*
x = n / (2^k - 1)

factor = 2; k = 1
while(k < 100) // 30 -> 10^9
    if(n % (factor - 1) == 0) return n/(factor - 1)
    factor *= 2;
*/