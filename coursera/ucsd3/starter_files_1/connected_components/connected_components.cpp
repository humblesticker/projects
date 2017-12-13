#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void explore(vector<vector<int>> &adj, vector<int> &from, int s) {
  stack<int> path; path.push(s); from[s] = s;
  while(!path.empty()) {
    int node = path.top(); path.pop();
    for(const auto &n : adj[node])
      if(from[n] < 0) { from[n] = node; path.push(n); }
  }
}

int number_of_components(vector<vector<int>> &adj) {
  int res = 0; vector<int> from(adj.size(), -1);
  for(int i=0; i<adj.size(); ++i)
    if(from[i] < 0) explore(adj, from, i);
  return res;
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
  std::cout << number_of_components(adj) << std::endl;
}
