#include <string>
using namespace std;

class BallAndHats {
public:
  int getHat(string hats, int numSwaps) {
  	if(numSwaps == 0 && hats[2] == 'o') return 2;
    if(hats[1] == 'o') numSwaps++;
    return numSwaps % 2;
  }
};
/*
check edge case and refactor
*/
