```cpp
pair<bool, int> solve(Node * root) {
  if(!root) return {true, 0};
  auto l = solve(root->left);
  auto r = solve(root->right);
  bool bal = abs(l.second - r.second) < 1;
  return {bal && l.first && r.first, max(l.second, r.second) + 1};
}

bool isBalanced(Node * root) {
  return solve(root).first;
}

```
