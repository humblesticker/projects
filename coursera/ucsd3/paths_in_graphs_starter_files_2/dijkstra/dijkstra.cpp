#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::cout;
using std::endl;

struct node { int id; int dist; };
bool operator<(const node &a, const node &b) { return a.dist > b.dist; }

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t) {
  vector<int> dist(adj.size(), -1);
  priority_queue<node> pq; pq.emplace(node { s, 0 }); dist[s] = 0;

  while(!pq.empty()) {
    const auto &item = pq.top(); int parent = item.id;
    if(parent == t) return item.dist;

    for(int i=0; i<adj[parent].size(); i++) {
      int child = adj[parent][i], w = cost[parent][i];
      if(dist[child] < 0 || dist[child] > dist[parent] + w) {
        dist[child] = dist[parent] + w;
        pq.emplace(node { child, dist[child] });
      }
    }
    pq.pop();
  }

  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t) << std::endl;
}
