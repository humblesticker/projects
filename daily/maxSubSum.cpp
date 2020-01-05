#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

/*
2 3 5 -5 2
2 3 5 -1 10
-10 2
2 3 -15 3 4
-10 -1 -> 0

collapse positive and negative region for simpler logic
5 -15 11 -10 100

sum = 0
iterate 
    if cur > max update max and range
    else 
        frontier += cur
        if(frontier > 0) 
            add frontier to range, update max and range
            reset frontier


on demand version
    if(cur >= 0) local += cur, continue
    else local = cur

    if local > max update max
    else 
        frontier += local
        if(frontier > 0) 
            add frontier to sum, update max
            frontier = 0
    
    local = 0

how about range
    need to track i, j also in addition to sum

*/

void sum(vector<int>& nums) {
    
}

int main() {
    int n; cin >> n; vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sum(nums);
    return 0;
}