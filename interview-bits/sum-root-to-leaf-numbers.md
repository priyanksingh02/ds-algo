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
```cpp
int ans;
void add(TreeNode* root, int n) {
    if(root) {
        n = n*10 + root->val;
        n %= 1003;
        if(!root->left && !root->right) {
            ans += n;
            ans %= 1003;
        }
        if(root->left)
            add(root->left, n);
        if(root->right)
            add(root->right, n);
    }
}
int Solution::sumNumbers(TreeNode* A) {
    if(!A) return 0;
    ans = 0;
    add(A, 0);
    return ans;
}
```
