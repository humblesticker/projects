#include <iostream>
#include <vector>
using std::vector;

/*
simple dfs

*/

void explore(int node, vector<vector<int>> &adj, vector<int> &from) {
  for(const auto &child : adj[node])
    if(!from[child] < 0) explore(child, adj, from);
}

int acyclic(vector<vector<int>> &adj) {

}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
