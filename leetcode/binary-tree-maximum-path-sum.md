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
    pair<int,int> path(TreeNode * root) {
        if(!root)
            return {-1e9, -1e9};
        auto left = path(root->left);
        auto right = path(root->right);
        int path = max({root->val, root->val + left.first, root->val+right.first});
        int maxlen = max({left.second, right.second, path, left.first + root->val + right.first});
        return {path, maxlen};
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        auto ans = path(root);
        return ans.second;
    }
};
```
