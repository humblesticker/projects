#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class ExpectedMinimumPowerDiv2 {
  double choose(int c, int k) {
    double count = 1.0; if(k > c-k) k = c-k;
    for(int i=1; i<=k; i++) {
      double coef = (double)(c-k+i)/i;
      count *= coef; cout << coef << "," << count << endl;
    }
    return count;
  }

public:
  double findExp(int n, int x) {
    double total = choose(n, x), avg = 0.0;

    for(int i=1; i<=n-x+1; i++) {
      int count = choose(n-i, x-1); cout << n-i << "," << x-1 << "," << count << endl;
      break;
      sum += count * pow(2.0, i);
      total += count;
    }

    return sum/total;
  }
};

int main() {
  ExpectedMinimumPowerDiv2 e;
  int n, x; cin >> n >> x;
  cout << setprecision(15)<< e.findExp(n, x) << endl;
  return 0;
}
