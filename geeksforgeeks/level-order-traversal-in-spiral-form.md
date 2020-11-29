```cpp
vector<int> findSpiral(Node* root) {
  if(!root) return {};
  queue<Node*> q;
  q.push(root);
  bool dir = true;
  vector<int> row, ans;
  while(!q.empty()) {
    int n = q.size();
    row.clear();
    for(int i = 0;i < n; ++i) {
      root = q.front();
      row.push_back(root->data);
      q.pop();
      if(root->left) q.push(root->left);
      if(root->right) q.push(root->right);
    }
    if(dir) reverse(row.begin(), row.end());
    dir^= true; // switch direction
    ans.insert(ans.end(), row.begin(), row.end());
  }
  return ans;
}
```
