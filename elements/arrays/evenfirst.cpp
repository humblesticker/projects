#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class evenfirst {
public:
  void order(vector<int> &nums) {
    int pos = 0;
    for(int i=0; i<nums.size(); i++)
      if(nums[i]%2 == 0) swap(nums[i], nums[pos++]);
  }
};

int main() {
  vector<int> nums { 1, 2, 3, 4 };
  evenfirst ef; ef.order(nums);
  for(auto n : nums) cout << n << ","; cout << endl;
  return 0;
}

/*
given array put even numbers first
O(n) time, O(1) space

1, 2, 3, 4

pos = 0
loop
  odd continue;
  even swap with next pos, update pos
*/
