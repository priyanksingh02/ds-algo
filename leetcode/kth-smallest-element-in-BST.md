```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
public:
    void search(TreeNode* root, int & k) {
        if(root) {
            search(root->left, k);
            k--;
            if(k == 0)
                ans = root->val;
            if(ans == -1) {
                search(root->right, k);
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        search(root, k);
        return ans;
    }
};
```
