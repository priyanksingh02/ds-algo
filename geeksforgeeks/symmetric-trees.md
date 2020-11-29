```cpp
bool check(Node * l, Node* r) {
  if(!l && !r) return true;
  if(!l or !r) return false;
  if(l->data != r->data) return false;
  return check(l->left, r->right) and check(l->right, r->left);
}
bool isSymmetric(Node* root) {
  if(!root) return true;
  return check(root->left, root->right);
}

```
