#include <vector>
using namespace std;

class quicksort {
public:
  void sort(vector<int> &nums) {

  }
};
/*
3, 2, 4, 5, 1

sort(nums)
  if(size < 2) return;

  pick a pivot (mid, random)
  swap with first
  4, 2, 3, 5, 1

  pos = 0
  from 1 to end
    if cur <= pivot pos++, swap with pos;
  4, 2, 3, 1, 5

  swap pos with 0
  1, 2, 3, 4, 5

  repeat with 0, pos and pos+1, end
*/
