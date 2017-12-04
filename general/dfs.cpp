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
  // how about undirected? from vector?
  void iterate(vector<vector<int>> &adj) {
    stack<int> path; path.push(1); vector<int> iter(adj.size());

    while(!path.empty()) {
      int node = path.top(), i = iter[node]; vector<int> list = adj[node];
      cout << "visiting:" << node << endl;
      if(list.size() == 0 || i >= list.size())  { path.pop(); }
      else { path.push(list[i]); iter[node]++; }
    }
  }

  void recurse(vector<vector<int>> &adj) {
      vector<int> from(adj.size());
      recurse(adj, from, 1);
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
  d.iterate(adj);
  d.recurse(adj);
}
