#include <bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node * left;
  node * right;
  node(int v): val{v}, left{nullptr}, right{nullptr} {}
};

// INPUT
vector<int> bt_{ 1, 2, 4, -1, 6, 5, -1, 3, -1, 4, 8, 9, -1, 0, 9, -1, -1, 3, 11 };

vector<int> inorder_iterative(node * root) {
  if(!root)
    return {};
  vector<int> ans;
  stack<node*> st;
  while(root) {
    while(root->left) {
      st.push(root);
      root = root->left;
    }
    ans.push_back(root->val);
    while(root && !root->right) {
      if(st.empty()) {
        root = nullptr;
        break;
      }
      root = st.top();
      st.pop();
      ans.push_back(root->val);
    }
    if(root && root->right) {
      root = root->right;
    }
  }
  return ans;
}

void push_all(stack<node*> & st, node * root) {
  while(root) {
    st.push(root);
    root = root->left;
  }
}

vector<int> inorder_easy(node * root) {
  stack<node*> st;
  vector<int> ans;
  push_all(st, root);
  while(!st.empty()) {
    root = st.top();
    st.pop();
    ans.push_back(root->val);
    if(root->right)
      push_all(st, root->right);
  }
  return ans;
}

// Helpers
void inorder(node* root) ;
node * build(vector<int> & v) ;

int main() {
  node * root = build(bt_);
  inorder(root);
  cout << endl;
  for(int x: inorder_iterative(root)) {
    cout << x << " ";
  }
  cout << endl;
  for(int x: inorder_easy(root)) {
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
