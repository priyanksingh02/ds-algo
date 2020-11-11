#include <bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node * left;
  node * right;
  node(int v): val{v}, left{nullptr}, right{nullptr} {}
};

// INPUT
vector<int> bt_{6, 3, 7, 1, 4, 5, 8, -1, 2, -1, -1, 6, 7, 7, 10};

// Flat Hierarchy based on depth and inorder traversal
//    Right
//  Root
//    Left
void draw(node * root, int depth) {
  if(root) {
    string notation;
    if(root->left && root->right)
      notation = "<";
    else if(root->right)
      notation = "/";
    else if(root->left) 
      notation = "\\";
    draw(root->right, depth + 1);
    cout << string(depth*4, ' ') << root->val << notation << endl;
    draw(root->left, depth + 1);
  }
}

void inorder_gen_nodes(node* root, vector<node*> & ans) {
  if(root) {
    inorder_gen_nodes(root->left, ans);
    ans.push_back(root);
    inorder_gen_nodes(root->right, ans);
  }
}

// Works for 1 digit visuals
// TODO Space needs to be adjusted for 2+ mixed digits nodes;
// TODO Add notation
void draw_vertical(node * root, vector<node*> in_order_nodes) {
  if(!root)
    return;
  queue<node*> q;
  q.push(root);
  while(!q.empty()) {
    int n = q.size();
    int cur = 0;
    for(int i = 0;i < n; ++i) {
      root = q.front();
      q.pop();
      auto iter = find(in_order_nodes.begin(), in_order_nodes.end(), root);
      assert(iter != in_order_nodes.end());
      int pos = iter - in_order_nodes.begin();
      int space = pos - cur;
      cur = pos+ 1; 
      cout << string(space, ' ') << root->val;
      if(root->left)
        q.push(root->left);
      if(root->right)
        q.push(root->right);
    }
    cout <<endl;
  }
}

// Helpers
void inorder(node* root) ;
node * build(vector<int> & v) ;

int main() {
  node * root = build(bt_);
  inorder(root);
  cout << endl;
  draw(root, 0);
  cout << endl;
  cout << "====Vertical=====";
  cout << endl;
  vector<node*> inorder_nodes;
  inorder_gen_nodes(root, inorder_nodes);
  draw_vertical(root, inorder_nodes);
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
