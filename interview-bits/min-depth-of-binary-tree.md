```cpp


int ans; 
void depth(TreeNode * root, int d) {
    if(root) {
        d += 1;
        if(!root->left && !root->right) {
            ans = min(ans, d);
        }
        depth(root->left, d);
        depth(root->right, d);
    }
}
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
    ans = INT_MAX;
    depth(A, 0);
    return ans;
}
```
