Didn't Work
```cpp
Node * head = nullptr;
Node * prev = nullptr;
Node * last = nullptr;

void inorder(Node * root) {
  if(root) {
    inorder(root->left);
    if(!head) head = root;
    root->left = prev;
    prev = root;
    last = root;
    inorder(root->right);
  }
}

Node * bToDLL(Node * root) {
  inorder(root);
  last->right = nullptr;
  while(last != head) {
    last->left->right = last;
    last = last->left;
  }
  return head;
}
```
