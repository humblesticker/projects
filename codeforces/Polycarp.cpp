#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int d, n; vector<int> flag(101);
    cin >> d; while(d-- > 0) { cin >> n; flag[n]++; }

    int max = 0;
    for(int n : flag) max = std::max(max, n); 
    cout << max << endl;
    return 0;
}