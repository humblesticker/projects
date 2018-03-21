#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class ExpectedMinimumPowerDiv2 {
public:
  double findExp(int n, int x) {
    double P = (double)x/n, E = P * 2;
    for(int i=1; i<n-x+1; i++) {
      P *= (double)(n-x-i+1)/(n-i);
      E += P * pow(2.0, i+1);
    }
    return E;
  }
};

int main() {
  ExpectedMinimumPowerDiv2 e;
  int n, x; cin >> n >> x;
  cout << setprecision(15) << e.findExp(n, x) << endl;
  return 0;
}
