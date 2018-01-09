#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class bfs {
public:
  void explore(vector<vector<int>> &adj, int node) {

  }
};

int main() {
  vector<vector<int>> adj(6, vector<int>(0)); // 0 is sentinel
  adj[1].push_back(2); adj[1].push_back(3);
  adj[2].push_back(4); adj[2].push_back(5);

  bfs b;
  b.explore(adj, 1);
}
