```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return bst(root, INT_MIN, INT_MAX);
    }
    
    bool bst(TreeNode * root, int mn , int mx) {
        bool ans = (root->val <= mx and root->val >= mn);
        if(ans and root->left) {
            if(root->val == INT_MIN) return false;
            ans &= bst(root->left, mn, root->val-1);
        }
        if(ans and root->right) {
            if(root->val == INT_MAX) return false;
            ans &= bst(root->right, root->val+1, mx);
        }
        return ans;
    }
};
```
