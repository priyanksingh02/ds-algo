```cpp
Node* LCA(Node* root, int p, int q) {
  if(!root) return nullptr;
  if(root->data == p || root->data == q)
    return root;
  auto l = LCA(root->left, p, q);
  auto r = LCA(root->right, p, q);
  if(l && r)
    return root;
  else if(!l)
    return r;
  else
    return l;
}
```
