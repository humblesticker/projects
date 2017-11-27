#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class MinProduct {
  long long min = LLONG_MAX;

  void navigate(vector<int>& nums, int blank1, int blank2, int i, int A, int B) {
    if(blank1 <= 0 && blank2 <= 0)
      min = std::min(min, (long long)A*B);

  	if(blank1 > 0) navigate(nums, blank1-1, blank2, i+1, A*10+nums[i], B);
  	if(blank2 > 0) navigate(nums, blank1, blank2-1, i+1, A, B*10+nums[i]);
  }

public:
  long long findMin(vector<int>& amount, int blank1, int blank2) {
    vector<int> nums;
    for(int i=0; i<amount.size(); i++)
      for(int j=0; j<amount[i]; j++) nums.push_back(i);
    navigate(nums, blank1, blank2, 0, 0, 0);
    return min;
  }
};

int main() {
  MinProduct mp;
  vector<int> amount = {0,1,1,2,1,1,0,0,0,0};
  cout << mp.findMin(amount, 2, 3) << endl;
  return 0;
}
