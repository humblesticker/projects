#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, num, prev = 0, stair = 0; cin >> n;
    vector<int> count;
    for(int i=0; i<n; i++) {
        cin >> num;
        if(num == 1 && i > 0) { count.push_back(prev); stair++; }
        prev = num;
    }
    count.push_back(prev); stair++; 

    cout << stair << "\n";
    for(int c : count) cout << c << " ";
    cout << "\n";
    return 0;
}
