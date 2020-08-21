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
const int mod = 1003;
void sum(TreeNode * root, int s, int & ans) {
    if(!root)
        return;
    s = (s * 10 + root->val)%mod;
    if(!root->left && !root->right) {
        ans += s;
        ans %= mod;
        return;
    }
    sum(root->left, s, ans);
    sum(root->right, s, ans);
} 

int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    sum(A, 0, ans);
    return ans;
}
```
