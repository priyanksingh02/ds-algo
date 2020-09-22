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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> ans;
        vector<int> row;
        bool level = false;
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(root) {
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                row.push_back(root->val);
            }
            else {
                if(!q.empty())
                    q.push(nullptr);
                if(level) {
                    reverse(row.begin(), row.end());
                }
                level ^= true;
                ans.push_back(row);
                row.clear();
            }
        }
        return ans;
    }
};
```
