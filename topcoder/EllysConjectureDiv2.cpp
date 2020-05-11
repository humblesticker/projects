#include <iostream>
using namespace std;

class EllysConjectureDiv2 {
  bool contains(int n, int L, int R) { return n >= L && n <= R; }

public:
  long long getSum(int L, int R) {
    int third = R/3 - (L-1)/3;
    long long sum = 4LL * (R - L + 1) + 2 * third;

    if(contains(1, L, R)) sum -= 3;
    if(contains(2, L, R)) sum -= 2;
    if(contains(3, L, R)) sum -= 3;
    return sum;
  }
};

int main() {
  int L, R; EllysConjectureDiv2 E;
  cin >> L >> R;
  cout << E.getSum(L, R) << endl;
  return 0;
}
