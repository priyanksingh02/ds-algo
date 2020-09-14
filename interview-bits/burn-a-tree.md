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
// B found, depth with/without B
pair<bool, int> depth(TreeNode* root, int b, int & ans) {
    bool found = false;
    int d = 0;
    if(root) {
        if(root->val == b) {
            return {true, 1};
        }
        auto left = depth(root->left, b, ans);
        if(left.first) {
            d = 1 + left.second;
            found = true;
        }
        auto right = depth(root->right, b, ans);
        if(right.first) {
            d = 1 + right.second;
            found = true;
        }
        if(!found) {
            d = 1 + max(left.second,right.second);
        }
        if(left.first or right.first)
            ans=max(ans, left.second + right.second);
    }
    return {found, d};
}

int Solution::solve(TreeNode* A, int B) {
    int ans = 0;
    auto p = depth(A, B, ans);
    return ans;
}
```
