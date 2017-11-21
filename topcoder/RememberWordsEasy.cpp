#include <utility>
#include <string>
using namespace std;

class RememberWordsEasy {
	pair<int, int> get(int d, int w) {
		int f = w/d, r = (d-1)/2;
		if(w%d == 0) return make_pair(f-r, f+r);
		return make_pair(min(f - r + 1, f + r), max(f - r + 1, f + r));
	}

public:
	string isPossible(int d1, int d2, int w1, int w2) {
		auto r1 = get(d1, w1), r2 = get(d2, w2);
		if(r1.first > r2.second && r1.first - r2.second > 1) return "Impossible";
		if(r2.first > r1.second && r2.first - r1.second > 1) return "Impossible";
		return "Possible";
	}
};

int main() {
	return 0;
}

/*
82, 7135, 5913, 5413 expect: Possible
*/