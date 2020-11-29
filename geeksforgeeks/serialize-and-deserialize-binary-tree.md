```cpp
// 0 can be used for nullptr as 1 <= root->val <= 1000
vector<int> serialize(Node * root) {
  vector<int> ans;
  queue<Node *> q;
  q.push(root);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    if(!root)
      ans.push_back(0);
    else {
      ans.push_back(root->data);
      q.push(root->left);
      q.push(root->right);
    }
  }
  return ans;
}

Node * deSerialize(vector<int> & A) {
  Node * root = nullptr;
  int i= 0;
  queue<Node * > q;
  if(A[i++]) {
    root = new Node(A[i-1]);
    q.push(root);
  }
  while(i < (int)A.size()) {
    Node * cur = q.front();
    q.pop();
    if(A[i++]) {
      cur->left = new Node(A[i-1]);
      q.push(cur->left);
    }
    if(A[i++]) {
      cur->right = new Node(A[i-1]);
      q.push(cur->right);
    }
  }
  return root;
}

```
