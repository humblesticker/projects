#include <vector>
#include <algorithm>
using namespace std;

class SoManyRectangles {
public:
	int maxOverlap(vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2) {
		int N = x1.size(), max = 0;
		for(int i=0; i<N; i++) {
			int count = 0;
			int lx = x1[i], ly = y1[i], ux = x2[i], uy = y2[i];

			for(int j=0; j<N; j++) {
				if(lx >= x2[j] || x1[j] >= ux) continue;
				if(ly >= y2[j] || y1[j] >= uy) continue;

				// update rectagle
				if(lx < x2[j]) ux = x2[j]; else lx = x1[j];
				if(ly < y2[j]) uy = y2[j]; else ly = y1[j];
				count++;
			}
			max = std::max(max, count);
		}
		return max;
	}
};
