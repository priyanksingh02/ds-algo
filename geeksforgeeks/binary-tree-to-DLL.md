Space Complexity: O(N)
Time Complexity: O(N)
```cpp
void inorder(Node* root, vector<Node*> & in) {
  if(root) {
    inorder(root->left,in);
    in.push_back(root);
    inorder(root->right,in);
  }
}

Node * bToDLL(Node *root)
{
  if(!root) return nullptr;
  vector<Node*> in;
  inorder(root, in);
  Node * prev = nullptr;
  for(Node* x: in) {
    x->left = prev;
    if(prev) prev->right = x;
    prev = x;
  }
  in.front()->left = nullptr;
  in.back()->right = nullptr;
  return in.front();
}

```


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
