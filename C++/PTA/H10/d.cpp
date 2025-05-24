#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
  int data;
  node *left, *right;
  node(int data) : data(data), left(nullptr), right(nullptr) {}
  node() : left(nullptr), right(nullptr) {}
};
void create_tree(node *&root, const vector<int> &post, const vector<int> &in) {
  if (post.empty() || in.empty())
    return;
  if (!root)
    root = new node;
  root->data = post.back();
  auto it = find(in.begin(), in.end(), root->data);
  int left_size = distance(in.begin(), it);
  int right_size = in.size() - left_size - 1;
  if (left_size == 0)
    root->left = nullptr;
  else
    create_tree(root->left, vector<int>(post.begin(), post.begin() + left_size),
                vector<int>(in.begin(), in.begin() + left_size));
  if (right_size == 0)
    root->right = nullptr;
  else
    create_tree(root->right,
                vector<int>(post.begin() + left_size, post.end() - 1),
                vector<int>(it + 1, in.end()));
}
void pre(node *root) {
  if (!root)
    return;
  cout << " " << root->data;
  pre(root->left);
  pre(root->right);
}
int main() {
  int n;
  cin >> n;
  vector<int> post(n), in(n);
  for (int &i : post)
    cin >> i;
  for (int &i : in)
    cin >> i;
  node *root = new node;
  create_tree(root, post, in);
  cout << "Preorder:";
  pre(root);
  return 0;
}