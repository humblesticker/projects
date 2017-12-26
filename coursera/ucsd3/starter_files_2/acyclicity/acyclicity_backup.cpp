#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::stack;

int explore(int node, int path, vector<vector<int>> &adj, vector<int> &visited) {
  stack<int> nav; nav.push(node);
  while(!nav.empty()) {
    int cur = nav.top(), count = 0;
    for(int i : adj[cur]) {
      if(visited[i] == path) return 1;
      if(visited[i]) continue;
      nav.push(i); visited[i] = path; count++;
    }
    if(count == 0) nav.pop();
  }
  return 0;
}

int acyclic(vector<vector<int>> &adj) {
  int path = 1, N = adj.size();
  vector<int> visited(N);

  for(int i=0; i<N; i++) {
    if(visited[i]) continue;
    if(explore(i, path, adj, visited)) return 1;
    path++;
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
  std::cout << acyclic(adj);
}
