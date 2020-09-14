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
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    TreeNode * root = new TreeNode(A->val + B->val);
    root->left = solve(A->left, B->left);
    root->right = solve(A->right, B->right);
    return root;
}
```
