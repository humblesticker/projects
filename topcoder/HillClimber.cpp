#include <vector>
#include <algorithm>

class HillClimber {
public:
	int longest(std::vector<int>& height) {
		int max = 0, local = 0;
		for(int i=1; i<height.size(); i++) {
			if(height[i] > height[i-1]) local++;
			if(i+1 >= height.size() || height[i+1] <= height[i]) {
				max = std::max(max, local); local = 0;
			}
		}
		return max;
	}	
};