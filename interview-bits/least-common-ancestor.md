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
int count(TreeNode* root, int B, int C) {
    if(!root)
        return 0;
    int ans = 0;
    if(root->val == B)
        ++ans;
    if(root->val == C)
        ++ans;
    return ans + count(root->left,B,C) + count(root->right,B,C);
} 

TreeNode * LCA(TreeNode * A, int B, int C) {
    if(!A || A->val == B || A->val == C)
        return A;
    TreeNode * l = LCA(A->left, B, C);
    TreeNode * r = LCA(A->right, B, C);
    if(!l)
        return r;
    if(!r)
        return l;
    return A;
}

int Solution::lca(TreeNode* A, int B, int C) {
    int c = count(A,B,C);
    if(c != 2)
        return -1;
    TreeNode * ans = LCA(A,B,C);
    return (ans)?ans->val:-1;
}
```
