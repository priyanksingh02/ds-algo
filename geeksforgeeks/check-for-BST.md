```cpp
bool check(Node * root, long low, long high) {
  if(!root)
    return true;
  if(root->data < low or root->data > high)
    return false;
  return check(root->left, low, root->data - 1) and check(root->right, root->data + 1, high);
}
bool isBST(Node* root) {
  return check(root, INT_MIN, INT_MAX);
}

```
