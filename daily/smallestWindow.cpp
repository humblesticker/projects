#include <tuple>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

/*
maxSoFar = min
start = -1, end = -1
iterate
    maxSoFar = max(maxSoFar, cur)
    
    if start < 0 
        if cur > next start = i
    else 
        if cur < maxSoFar end = i

    cout << start << end;
*/
class smallest {
public:
    int start(vector<int>& nums) {
        vector<int> minSoFar(nums.size());
        int min = numeric_limits<int>::max();

        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] < min) min = nums[i];
            minSoFar[i] = min;
        }

        for(int i=0; i<nums.size(); i++)
            if(nums[i] > minSoFar[i]) return i;
        return -1;
    }

    int end(vector<int>& nums) {
        vector<int> maxSoFar(nums.size());
        int max = numeric_limits<int>::min();

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > max) max = nums[i];
            maxSoFar[i] = max;
        }

        for(int i=nums.size()-1; i>=0; i--) 
            if(nums[i] < maxSoFar[i]) return i;
        return -1;
    }

    tuple<int, int> getWindow(vector<int>& nums) {
        return make_tuple(start(nums), end(nums));
    } 
};

int main() {
    int n; cin >> n; vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    smallest s;
    auto range = s.getWindow(nums);
    cout << get<0>(range) << "," << get<1>(range) << endl;
    return 0;
}