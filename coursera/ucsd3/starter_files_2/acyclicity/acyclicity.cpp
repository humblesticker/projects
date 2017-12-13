#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int acyclic(vector<vector<int>> &adj) {
  //write your code here
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
/*
visited, path = 1
loop node
  if visited continue
  explore
  path++


explore
  push node to stack
  while stack is not empty
    cur = top
    if(cur is visited)
      if same path return 1
      else continue
    else
      if no unvisisted child pop // post
      else add children to stack // pre
*/
