```cpp
class Solution {
    int value = 0;
public:
    void inorder(TreeNode * root) {
        if(root) {
            convertBST(root->right);
            root->val += value;
            value = root->val;
            convertBST(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
};
```
