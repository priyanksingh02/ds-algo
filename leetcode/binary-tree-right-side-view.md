```cpp
class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
      if(!root) return {};
      vector<int> ans;
      queue<TreeNode*> q;
      q.push(root);
      int last = 0;
      while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; ++i) {
          root = q.front();
          q.pop();
          last = root->val;
          if(root->left) q.push(root->left);
          if(root->right) q.push(root->right);
        }
        ans.push_back(last);
      }
      return ans;
    }
};
```
