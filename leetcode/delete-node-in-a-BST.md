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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        if(root->val == key) {
            if(!root->left)
                return root->right;
            if(!root->right) 
                return root->left;
            TreeNode * p = root->right;
            TreeNode * pprev = nullptr;
            while(p->left) {
                pprev = p;
                p = p->left;
            }
            swap(p->val, root->val);
            if(!pprev) {
                root->right = p->right;
            }
            else {
                pprev->left = p->right;
            }
            // delete p;
            return root;
        }
        else {
            TreeNode * p = root;
            TreeNode * pprev = nullptr;
            while(p && p->val != key) {
                pprev = p;
                if(p->val < key) {
                    p = p->right;
                }
                else {
                    p = p->left;
                }
            }
            if(!p)
                return root;
            assert(pprev != nullptr);
            if(!p->left) {
                if(pprev->left == p) {
                    pprev->left = p->right;
                }
                else {
                    pprev->right = p->right;
                }
            }
            else if(!p->right) {
                if(pprev->left == p) {
                    pprev->left = p->left;
                }
                else {
                    pprev->right = p->left;
                }
            }
            else {
                TreeNode * q = p->right;
                TreeNode * qprev = nullptr;
                while(q->left) {
                    qprev = q;
                    q = q->left;
                }
                swap(q->val, p->val);
                if(!qprev) {
                    p->right = q->right;    
                }
                else {
                    qprev->left = q->right;
                }
            }
            // delete q;
            return root;
            
        }
    }
        
};
```
