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
 int ans , cnt;
void search(TreeNode * root, int key) {
    if(root) {
        search(root->left, key);
        if(++cnt == key)
            ans = root->val;
        search(root->right, key);
    }
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    cnt = ans = 0;
    search(A, B);
    return ans;
}
```
