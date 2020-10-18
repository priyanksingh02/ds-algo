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
TreeNode * p; // previous to root
int larger, smaller;
void inorder(TreeNode * root) {
    if(root) {
        inorder(root->left);
        if(p && p->val > root->val) {
            larger = max(larger, p->val);
            smaller = min(smaller, root->val);
        }
        p = root;
        inorder(root->right);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    p = nullptr;
    larger = INT_MIN, smaller = INT_MAX;
    inorder(A);
    return {smaller, larger};
}
```
