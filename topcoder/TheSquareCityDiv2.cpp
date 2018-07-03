/*
for each house
	while there are warmer houses in range
		move to warmest
		- count prev loc and + count new loc

find all houses in range
	x from -r to r
		y from -r to r
			if in range track max t and loc
	return warmest

	-r or r is out of range truncate to 0 to n-1
*/
#include <vector>
#include <cmath>
using namespace std;

struct house { int t; int x; int y; };

class TheSquareCityDiv2 {

	// return max, x, y
	house warmest(int x, int y, int r, int n, vector<int> &h, vector<int> &t) {
		int x1 = max(x-r, -n), x2 = min(x+r, n), y1 = max(y-r, -n), y2 = min(y+r, n);
    int mt = 0, mx = -1, my = -1;

		for(int i=x1; i<=x2; i++)
			for(int j=y1; j<=y2; j++) {
        // if x-i + y-j <= r update max
			}

    house hs { mt, mx, my };
		return hs;
	}

public:
	vector<int> find(int r, vector<int> &t) {
		int size = t.size(), n = (int)sqrt(size);
		vector<int> h(size, 1);

		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++) {
        int cx = x, cy = y;
				while(true) {
					int i = cx*n + cy; house found = warmest(cx, cy, r, n, h, t);
					if(found.t <= t[i]) break;
          cx = found.x; cy = found.y; h[i]--; h[cx*n + cy]++;
				}
      }

      int count = 0, max = 0;

      vector<int> result = { count, max };
      return result;
   }
};

int main() {
  return 0;
}
