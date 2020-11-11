#include <bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node * left;
  node * right;
  node(int v): val{v}, left{nullptr}, right{nullptr} {}
};

// INPUT
vector<int> bt_{ 1, 2, 4, -1, 6 };

vector<int> level_order(node* root) {
  if(!root)
    return {};
  vector<int> ans;
  queue<node*> q;
  q.push(root);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    ans.push_back(root->val);
    if(root->left)
      q.push(root->left);
    if(root->right)
      q.push(root->right);
  }
  return ans;
}

// Helpers
void inorder(node* root) ;
node * build(vector<int> & v) ;

int main() {
  node * root = build(bt_);
  for(int x: level_order(root)) {
    cout << x << " ";
  }
  cout << endl;
}

void inorder(node* root) {
  if(root) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

node * build(vector<int> & v) {
  if(v.empty())
    return nullptr;
  node * root = new node(v[0]);
  queue<node *> q;
  q.push(root);
  for(int i = 1; i < (int)v.size(); i+=2) {
    node * cur = q.front();
    q.pop();
    if(v[i] != -1) {
      cur->left = new node(v[i]);
      q.push(cur->left);
    }
    assert(i+1 < (int)v.size());
    if(v[i+1] != -1) {
      cur->right = new node(v[i+1]);
      q.push(cur->right);
    }
  }
  return root;
}
