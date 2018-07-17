#include <iostream>
#include <unordered_map>
using namespace std;

bool find(unordered_map<int, int> &mm, int val) {
    for(int i=1; i<32; i++) {
        int num = (1 << i) - val; 
        auto found = mm.find(num); 
        if(found == mm.end() || (num == val && found->second < 2)) continue; 
        return true;
    }
    return false;
}

int main() {
    int n, d, count = 0; cin >> n; unordered_map<int, int> mm; 
    for(int i=0; i<n; i++) { cin >> d; mm[d]++; }

    for(const auto &pair : mm)
        if(!find(mm, pair.first)) count += pair.second;

    cout << count << "\n"; 
    return 0;
}