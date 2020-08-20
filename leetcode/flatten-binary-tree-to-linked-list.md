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
public:
    void flatten(TreeNode* root) {
        TreeNode * p = root;
        while(p) {
            if(p->left) {
                TreeNode * l = p->left;
                while(l->right) {
                    l = l->right;
                }
                l->right = p->right;
                p->right = p->left;
                p->left = nullptr;
            }
            else {
                p = p->right;
            }
        }
    }
};
```
