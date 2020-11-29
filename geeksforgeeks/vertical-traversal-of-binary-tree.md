```cpp
vector<int> verticalOrder(Node* root) {
  if(!root) return {};
  map<int, vector<int>> hash;
  queue<pair<Node*, int>> q;
  q.push({root, 0});
  while(!q.empty()) {
    root = q.front().first;
    int rank= q.front().second;
    q.pop();
    hash[rank].push_back(root->data);
    if(root->left) q.push({root->left, rank - 1});
    if(root->right) q.push({root->right, rank + 1});
  }
  vector<int> ans;
  for(auto & x: hash) {
    ans.insert(ans.end(), x.second.begin(), x.second.end());
  }
  return ans;
}

```
