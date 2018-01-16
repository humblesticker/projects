#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class bfs {
public:
  void explore(vector<vector<int>> &adj, int node) {
    vector<int> from(adj.size());
    queue<int> q; q.push(node);
    while(!q.empty()) {
      int front = q.front(); cout << front << endl;
      for(int child : adj[front])
        if(from[child] == 0) { from[child] = front; q.push(child); }
      q.pop();
    }
  }
};

int main() {
  vector<vector<int>> adj(6, vector<int>(0)); // 0 is sentinel
  adj[1].push_back(2); adj[1].push_back(3);
  adj[2].push_back(4); adj[2].push_back(5);

  bfs b;
  b.explore(adj, 1);
}
