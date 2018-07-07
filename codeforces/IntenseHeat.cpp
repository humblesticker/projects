#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class IntenseHeat {
    double get(int sum, int size, vector<int> &nums) {
        int max = sum, i = 0, j = size-1;

        while(j+1 < nums.size()) {
            sum = sum - nums[i++] + nums[++j];
            max = std::max(max, sum);
        }
        
        return (double)max/size;
    }

public:
    double get(int k, vector<int> &nums) {
        int sum = 0; for(int i=0; i<k-1; i++) sum += nums[i];
        double max = 0.0;

        for(int size=k; size<=nums.size(); size++) {
            sum += nums[size-1];
            max = std::max(max, get(sum, size, nums)); 
        }

        return max;
    }
};

int main() {
    int k, n, t; IntenseHeat IH;
    cin >> n >> k;

    vector<int> nums; while(n-- > 0) { cin >> t; nums.push_back(t); }
    cout << std::setprecision(15) << IH.get(k, nums) << endl;
    return 0;
}