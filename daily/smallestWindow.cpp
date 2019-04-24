#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

void range(vector<int>& nums) {
    int maxSoFar = numeric_limits<int>::min(), start = -1, end = -1, N = nums.size();
    
    for(int i=0; i<N; i++) {
        maxSoFar = max(maxSoFar, nums[i]);
        if(start < 0) { if(i+1 < N && nums[i] > nums[i+1]) start = i; }
        else { if(nums[i] < maxSoFar) end = i; }
    }

    cout << start << "," << end << endl;
}

int main() {
    int n; cin >> n; vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    range(nums);
    return 0;
}