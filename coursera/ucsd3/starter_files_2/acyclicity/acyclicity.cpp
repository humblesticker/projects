#include <iostream>
#include <vector>
using std::vector;

bool reach(vector<vector<int>> &adj, int src, int dest, vector<bool> &visited) {
  if(src == dest) return true;
  for(auto child : adj[src]) {
    if(visited[child]) continue;
    visited[child] = true;
    if(reach(adj, child, dest, visited)) return true;
  }
  return false;
}

int cyclic(vector<vector<int>> &adj) {
  for(int i=0; i<adj.size(); i++)
    for(auto src : adj[i]) {
      vector<bool> visited(adj.size());
      if(reach(adj, src, i, visited)) return 1;
    }
  return 0;
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
  std::cout << cyclic(adj) << std::endl;
}
