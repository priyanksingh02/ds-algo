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
bool check(TreeNode * l, TreeNode *r ) {
    if(!l && !r)
        return true;
    if(!l or !r)
        return false;
    if(l->val != r->val)
        return false;
    return check(l->left, r->right) and check(l->right, r->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(!A)
        return true;
    return check(A->left, A->right);
}
```
