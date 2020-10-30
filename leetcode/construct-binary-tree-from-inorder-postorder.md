```cpp
class Solution {
public:
    TreeNode * build(vector<int> & in, vector<int>& post, int i, int j, int pi, int pj) {
        if(i > j or pi > pj)
            return nullptr;
        TreeNode * root = new TreeNode(post[pj]);
        int k = i;
        for(; k <= j; ++k) {
            if(in[k] == post[pj]) {
                break;
            }
        }
        int cnt = k - i;
        root->left = build(in, post, i, k - 1, pi, pi+cnt-1);
        root->right = build(in, post, k+1, j, pi+cnt, pj-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n-1, 0, n-1);
    }
};
```
