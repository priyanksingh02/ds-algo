```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        TreeNode* root = q.front();
        q.pop();
        while(root) {
            ans.push_back(root->val);
            if(root->left)
                q.push(root->left);
            root = root->right;
        }
    }
    return ans;
}
```
