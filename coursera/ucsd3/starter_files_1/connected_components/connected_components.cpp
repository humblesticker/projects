#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

int next(vector<int> &from, int start) {
  for(int i=start; i<from.size(); ++i) if(from[i] < 0) return i;
  return -1;
}

void explore(vector<vector<int>> &adj, vector<int> &from, int node, int res) {
  vector<int> iter(adj.size()); stack<int> path; path.push(node); from[node] = node;
  while(!path.empty()) {
    int n = path.top(), i = iter[n]; vector<int> &list = adj[n];

    if(list.size() == 0 || i >= list.size()) path.pop();
    else {
      int cur = list[i]; iter[n] = i+1;
      if(from[cur] < 0) { path.push(cur); from[cur] = n; }
    }
  }
}

int number_of_components(vector<vector<int>> &adj) {
  int res = 0, node = 0;
  vector<int> from(adj.size(), -1);

  do {
    explore(adj, from, node, res);
    node = next(from, node+1); ++res;
  } while(node > 0);

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
