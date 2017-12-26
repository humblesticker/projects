/*
systemic

simple
  # of free cell: all - one path
  if odd Hero wins
*/
#include <vector>
#include <string>
using namespace std;

class TurtleGame {
public:
  vector<string> getwinner(vector<string> &board) {
      int row = board.size(), col = board[0].length(), count = 0;
      for(const string &s : board) for(const char &c : s)
        if(c == '.') count++;
      return (count - row - col + 1)%2 == 1;
  }
};
