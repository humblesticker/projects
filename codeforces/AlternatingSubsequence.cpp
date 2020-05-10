#include <iostream>
#include <algorithm>
using namespace std;

class AlternatingSubsequence {
public:
    long long maxSum() {
        int n, local, cur; cin >> n >> local; 
        if(n == 1) return local;

        long long sum = 0;
        for(int i=1; i<n; i++) {
            cin >> cur; 
            if((local ^ cur) < 0) { sum += local; local = cur; }
            else local = max(local, cur);
        }

        return sum + local; // last sum
    }
};

int main() {
    int t; AlternatingSubsequence C;
    cin >> t;
    while(t-- > 0) cout << C.maxSum() << endl;
    return 0;
}