#include <string>
using namespace std;

class TopXorerEasy {
public:
  int maximalRating(int A, int B, int C) {
    int result = 0; int nums[] = { A, B, C };

    for(int i=30; i>=0; i--) {
      int mask = 1 << i, count = 0;
      for(auto n : nums) if((n & mask) >> i) count++;
      if(count > 1) return result + 2*mask - 1;
      if(count == 1) result |= mask;
    }
    return result;
  }
};
