```cpp
vector<int> leftView(Node *root)
{
  vector<int> ans;
  while(root) {
    ans.push_back(root->data);
    if(root->left) root = root->left;
    else root = root->right;
  }
  return ans;
}
```
