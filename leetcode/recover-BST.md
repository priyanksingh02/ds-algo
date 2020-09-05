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
    TreeNode * prev;
    TreeNode * big, *small;
public:
    void inorder(TreeNode * root) {
        if(root) {
            inorder(root->left);
            if(prev && prev->val > root->val) {
                small = root;
                if(!big) big = prev;
            }
            prev = root;
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        prev = big = small = nullptr;
        inorder(root);
        swap(big->val, small->val);
    }
};
```
