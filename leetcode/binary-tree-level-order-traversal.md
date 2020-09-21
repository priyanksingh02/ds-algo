```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> row;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(root) {
                row.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            else {
                ans.push_back(row);
                row.clear();
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        return ans;
    }
};
```
