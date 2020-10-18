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
bool ans;
int check(TreeNode * root) {
    if(!root)
        return 0;
    int l = check(root->left);
    int r = check(root->right);
    if(abs(l - r) > 1)
        ans = false;
    return 1 + max(l,r);
}
int Solution::isBalanced(TreeNode* A) {
    ans = true;
    check(A);
    return ans;
}
```
