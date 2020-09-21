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
    bool check(TreeNode * l, TreeNode * r) {
        if(!l and !r)
            return true;
        if(!l or !r)
            return false;
        if(l->val != r->val)
            return false;
        return check(l->left, r->right) and
            check(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left, root->right);
    }
};
```
