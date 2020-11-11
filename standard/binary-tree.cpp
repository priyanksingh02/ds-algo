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





// Helpers
void inorder(node* root) ;
node * build(vector<int> & v) ;

int main() {
  node * root = build(bt_);
  inorder(root);
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
