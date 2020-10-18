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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A and !B)
        return true;
    if(!A or !B)
        return false;
    if(A->val != B->val)
        return false;
    return isSameTree(A->left, B->left) and isSameTree(A->right, B->right);
}

```
