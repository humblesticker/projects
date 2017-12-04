#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Pos { int x; int y; };

bool cmp(const Pos& p1, const Pos& p2) { return p1.y - p2.y; }

class CatchTheBeatEasy {
public:
	string ableToCatchAll(vector<int> x, vector<int> y) {
		vector<Pos> ps; ps.push_back({0, 0});
		for(int i=0; i<x.size(); i++) ps.push_back({x[i], y[i]});
		sort(ps.begin(), ps.end(), cmp);

		for(int i=1; i<ps.size(); i++)
			if(abs(ps[i].y - ps[i-1].y) < abs(ps[i].x - ps[i-1].x))  return "Not able to catch";

		return "Able to catch";
	}
};

int main() {
  CatchTheBeatEasy c;
  cout << c.ableToCatchAll(
    {19, 6, 16, 4, -9, -10, -1, -11, -17, 5, 2, 4, 25, 36, 10, 12, -8, 13, 19, 15, 12, 22, 20, 7, 0, -8, 6, -11, 4, 24, 12, 10, 14, 17, 11, -8, 22, 5, -8, 7, 5, -3, 9},
    {132, 471, 126, 455, 395, 422, 538, 433, 409, 226, 358, 254, 305, 152, 234, 58, 377, 208, 299, 340, 39, 175, 180, 88, 17, 510, 49, 549, 496, 317, 63, 37, 105, 293, 233, 377, 313, 493, 531, 71, 200, 270, 213}
  ) << endl;
}
