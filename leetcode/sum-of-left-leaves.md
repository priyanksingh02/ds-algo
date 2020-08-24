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
    int ans;
public:
    void sum(TreeNode * root, bool left) {
        if(root) {
            if(!root->left and !root->right and left)
                ans += root->val;
            if(root->left)
                sum(root->left, true);
            if(root->right)
                sum(root->right, false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        sum(root, false);
        return ans;
    }
};
```
