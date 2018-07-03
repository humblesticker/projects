/*
REFACTOR
  iterative [x] or recursive
  use next_permutation

REFLECT
  x0/x1 - x2 = 0
  x0 - x1*x2 = x1*d -> wrong logic/conjecture

EXTEND
permutate
  0, 1, 2
  0, 2, 1
  1, 0, 2
  1, 2, 0
  2, 0, 1
  2, 1, 0

combinate
*/
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class MinimizeAbsoluteDifferenceDiv2 {
	double calculate(int i, int j, int k, vector<int> &nums) {
		return abs((double)nums[i]/nums[j] - nums[k]);
	}

public:
	vector <int> findTriple(int x0, int x1, int x2) {
		vector<int> nums { x0, x1, x2 }, pos { 0, 1, 2 };
		double min = calculate(0, 1, 2, nums);

		for(int i=0; i<3; i++) for(int j=0; j<3; j++) { if(j == i) continue;
			for(int k=0; k<3; k++) { if(k == i || k == j) continue;
				double local = calculate(i, j, k, nums);
				if(local < min) { min = local; pos[0] = i; pos[1] = j; pos[2] = k; }
			}
		}

		return pos;
	}
};
