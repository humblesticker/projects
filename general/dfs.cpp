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
  void navigate(vector<vector<int>> &adj) {
    stack<int> path; path.push(1); vector<int> iter(adj.size());

    while(!path.empty()) {
      int node = path.top(), i = iter[node]; vector<int> list = adj[node];
      if(list.size() == 0 || i >= list.size())  { path.pop(); }
      else { path.push(list[i]); iter[node]++; }
    }
  }
};

int main() {
  dfs d;
  vector<vector<int>> adj(6, vector<int>(0)); // 0 is sentinel
  adj[1].push_back(2); adj[1].push_back(3);
  adj[2].push_back(4); adj[2].push_back(5);
  d.navigate(adj);
}
