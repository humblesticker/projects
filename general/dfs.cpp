/*
recursive ok ~ 10^5
using stack to simulate recursive call
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class dfs {
public:
  void iterate(vector<vector<int>> &adj, int s) {
    vector<int> from(adj.size());
    stack<int> path; path.push(s); from[s] = s;

    while(!path.empty()) {
      int node = path.top(); path.pop(); cout << "visiting:" << node << endl;
      for(const auto &n : adj[node])
        if(from[n] == 0) { from[n] = node; path.push(n); }
    }
  }

  void recurse(vector<vector<int>> &adj, int s) {
      vector<int> from(adj.size());
      recurse(adj, from, s);
  }

  void recurse(vector<vector<int>> &adj, vector<int> &from, int node) {
    cout << "visiting:" << node << endl;
    for(auto i : adj[node])
      if(from[i] == 0) { from[i] = node; recurse(adj, from, i); }
  }
};

int main() {
  vector<vector<int>> adj(6, vector<int>(0)); // 0 is sentinel
  adj[1].push_back(2); adj[1].push_back(3);
  adj[2].push_back(4); adj[2].push_back(5);

  dfs d;
  d.iterate(adj, 1);
  //d.recurse(adj, 1);
}
