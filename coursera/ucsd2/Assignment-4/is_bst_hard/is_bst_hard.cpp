#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

// if left is null from parent to right equal is allowd
bool navigate(int i, vector<int> &keys, const vector<Node> &tree) {
  if(i < 0) return true;
  auto node = tree[i];
  
  if(!navigate(node.left, keys, tree)) return false;

  int size = keys.size(); 
  if(size > 0) {
    if(node.left < 0) { if(node.key < keys[size-1]) return false; }
    else { if(node.key <= keys[size-1]) return false; }
  } 
  keys.push_back(node.key);

  return navigate(node.right, keys, tree);
}

bool IsBinarySearchTree(const vector<Node> &tree) {
  if(tree.size() <= 0) return true;
  vector<int> keys;
  return navigate(0, keys, tree);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
