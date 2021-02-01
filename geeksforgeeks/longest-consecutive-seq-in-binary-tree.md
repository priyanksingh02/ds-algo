```cpp
pair<int,int> count(Node* root) {
  if(!root) return {0,0};
  if(!root->left and !root->right) return {1,1};
  auto l = count(root->left);
  auto r = count(root->right);
  int cur = 1;
  if(root->left && root->left->data == root->data + 1)
    cur = l.second + 1;
  if(root->right && root->right->data == root->data + 1 && cur < r.second+1)
    cur = r.second + 1;
  return {max({l.first, r.first, cur}), cur};
}

int longestConsecutive(Node* root) {
  int ans = count(root).first;
  if(ans < 2) return -1;
  else return ans;
}
```
