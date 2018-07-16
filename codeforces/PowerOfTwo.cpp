#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool find(vector<int> &power, unordered_map<int, unordered_set<int>> &mm, int val, int pos) {
    for(auto p : power) {
        auto found = mm.find(p - val); if(found == mm.end()) continue;
        for(auto s : found->second) if(s != pos) return true;
    }
    return false;
}

int main() {
    int n, count = 0; cin >> n; 
    unordered_map<int, unordered_set<int>> mm; vector<int> nums(n), power(31);
    for(int i=0; i<nums.size(); i++) { cin >> nums[i]; mm[nums[i]].insert(i); }
    for(int i=0, f=1; i<power.size(); i++, f*=2) power[i] = f;

    for(int i=0; i<nums.size(); i++) if(!find(power, mm, nums[i], i)) count++; 
    cout << count << "\n"; 
    return 0;
}