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
TreeNode * build(vector<int> & in, int inl, int inh, vector<int> &post, int postl, int posth) {
    if(inl > inh)
        return nullptr;
    if(inl == inh)
        return new TreeNode (in[inl]);
    TreeNode * root = new TreeNode(post[posth]);
    int i = inl;
    for(; i <= inh; ++i) {
        if(in[i] == post[posth])
            break;
    }
    int cnt = i - inl;
    root->left = build(in, inl, i-1, post, postl, postl + cnt - 1);
    root->right = build(in, i+1, inh, post, postl + cnt, posth-1);
    return root;
} 

TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    return build(in, 0, (int)in.size() -1 , post, 0, (int)post.size() -1);
}
```
