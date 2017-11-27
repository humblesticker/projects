#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(const vector<string>& ops) {
        vector<int> nums;
        for(const auto& op : ops) {
            int len = nums.size();
            if(op == "C") { if(len > 0) nums.pop_back(); }
            else if(op == "+") { if(len > 1) nums.push_back(nums[len-2] + nums[len-1]); }
            else if(op == "D") { if(len > 0) nums.push_back(2 * nums[len-1]); }
            else nums.push_back(stoi(op));
        }

        int sum = 0; for(const auto& n : nums) sum += n;
        return sum;
    }
};

int main() {
  Solution s;
  cout << s.calPoints({"5","2","C","D","+"}) << endl;
  return 0;
}
