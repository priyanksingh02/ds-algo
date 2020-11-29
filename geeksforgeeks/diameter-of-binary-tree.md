```cpp
// height, max diameter
pair<int,int> solve(Node* root) {
  if(!root) return {0,0};
  auto l = solve(root->left);
  auto r = solve(root->right);
  int h_max = max(l.first, r.first) + 1;
  int d = l.first + r.first + 1;
  return {h_max, max({d, l.second, r.second})};
}

int diameter(Node * root) {
  return solve(root).second;
}

```
