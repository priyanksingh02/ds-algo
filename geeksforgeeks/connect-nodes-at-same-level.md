```cpp
void connect(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    int n = q.size();
    Node * prev = nullptr;
    for(int i = 0;i < n; ++i) {
      root = q.front();
      q.pop();
      root->nextRight = prev;
      prev = root;
      if(root->right) q.push(root->right);
      if(root->left) q.push(root->left);
    }
  }
}

```
