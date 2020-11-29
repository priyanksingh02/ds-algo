```cpp
vector <int> bottomView(Node *root)
{
  if(!root) return {};
  map<int,int> hash;
  queue<pair<Node*, int>> q;
  q.push({root, 0});
  while(!q.empty()) {
    root = q.front().first;
    int rank = q.front().second;
    q.pop();
    hash[rank] = root->data;
    if(root->left) {
      q.push({root->left, rank - 1});
    }
    if(root->right) {
      q.push({root->right, rank + 1});
    }
  }
  vector<int> ans;
  for(auto & x: hash)
    ans.push_back(x.second);
  return ans;
}
```
