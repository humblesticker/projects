#include <iostream>
#include <vector>

using std::vector;
using std::pair;

/*
dfs from x, check if y is visited

*/
void explore(vector<vector<int>> &adj, vector<int> &from, int node, int y) {
  for(const auto &i : adj[node])
    if(from[i] == 0) {
      from[i] = node; if(i == y) return;
      explore(adj, from, i, y);
    }
}

int reach(vector<vector<int>> &adj, int x, int y) {
  vector<int> from(adj.size());
  explore(adj, from, x, y);
  return from[y] > 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) << std::endl;
}
