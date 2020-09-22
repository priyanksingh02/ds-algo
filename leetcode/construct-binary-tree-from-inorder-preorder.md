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
    TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        TreeNode * root = new TreeNode (preorder[0]);
        if(preorder.size() == 1)
            return root;
        int i = 0;
        for(; i < inorder.size(); ++i) {
            if(preorder[0] == inorder[i])
                break;
        }
        // root->left = buildTree({&preorder[1], &preorder[1+i]},
                               // {&inorder[0], &inorder[i]});
        root->left = buildTree({preorder.begin() + 1, preorder.begin()+i+1},
                               {inorder.begin(), inorder.begin()+i});
        // root->right=  buildTree({&preorder[i+1], preorder.end()},
                                // {&inorder[i+1], inorder.end()});
        root->right = buildTree({preorder.begin()+i+1, preorder.end()},
                                {inorder.begin()+i+1, inorder.end()});
        return root;
    }
};
```
