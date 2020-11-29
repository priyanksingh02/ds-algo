Didn't Work
```cpp
// height sum, maxpathsum
pair<int,int> solve(Node* root) {
  if(!root) return {0,0};
  auto l = solve(root->left);
  auto r = solve(root->right);
  int h_sum = max({0, l.first, r.first}) + root->data;
  int path_sum = max(h_sum, l.first + root->data + r.first);
  return {h_sum , max({path_sum, l.second, r.second})};
}

int maxPathSum(Node* root) {
  if(!root) return 0;
  return solve(root).second;
}

```
