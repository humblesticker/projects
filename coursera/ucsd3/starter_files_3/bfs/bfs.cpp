#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> dist(adj.size(), -1);
  queue<int> q; q.push(s); dist[s] = 0;

  while(!q.empty()) {
    int front = q.front(); if(front == t) return dist[front];
    for(int node : adj[front])
      if(dist[node] < 0) { dist[node] = dist[front] + 1; q.push(node); }
    q.pop();
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
/*
dist array to measure
bfs from s
  if t is met return dist
return -1

*/
