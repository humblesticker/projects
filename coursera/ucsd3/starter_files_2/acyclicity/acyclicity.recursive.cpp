#include <iostream>
#include <vector>
using std::vector;

bool hasCycle(int node, vector<vector<int>> &adj, vector<int> &from) {
  for(const auto &child : adj[node]) {
    if(from[child] == from[node]) return true;
    if(from[child] > 0) continue;
    from[child] = from[node];
    if(hasCycle(child, adj, from)) return true;
  }
  return false;
}

int cyclic(vector<vector<int>> &adj) {
  int N = adj.size(), path = 1; vector<int> from(N)
  for(int i=0; i<N; i++) {
    if(from[i] > 0) continue;
    from[i] = path++;
    if(hasCycle(i, adj, from)) return 1;
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
