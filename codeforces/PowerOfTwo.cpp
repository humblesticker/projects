#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool find(unordered_map<int, int> &mm, vector<int> &power, int val) {
    for(const auto &p : power) { 
        auto found = mm.find(p - val); 
        if(found == mm.end() || (val == p - val && found->second < 2)) continue; 
        return true;
    }
    return false;
}

int main() {
    int n, d, count = 0; cin >> n; 
    unordered_map<int, int> mm; vector<int> power(31);
    for(int i=0; i<n; i++) { cin >> d; mm[d]++; }
    for(int i=0, f=1; i<power.size(); i++, f*=2) power[i] = f;

    for(const auto &pair : mm)
        if(!find(mm, power, pair.first)) count += pair.second;

    cout << count << "\n"; 
    return 0;
}