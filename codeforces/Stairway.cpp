#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    int cur, prev; cin >> prev;
    vector<int> steps;

    for(int i=1; i<n; i++) {
        cin >> cur; if(cur == 1) steps.push_back(prev); 
        prev = cur;
    }
    steps.push_back(prev); 

    cout << steps.size() << "\n";
    for(int step : steps) cout << step << " ";
    return 0;
}