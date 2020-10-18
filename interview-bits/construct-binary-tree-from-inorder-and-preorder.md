```cpp
TreeNode * build(vector<int> & in, int l , int r, vector<int> & pre, int lp, int rp) {
    if(l > r)
        return nullptr;
    if(l == r)
        return new TreeNode(in[l]);
    TreeNode * root = new TreeNode(pre[lp]);
    int i = l;
    for(; i <= r; ++i) {
        if(in[i] == pre[lp])
            break;
    }
    int cnt = i - l;
    root->left = build(in, l, i-1, pre, lp +1, lp+cnt);
    root->right = build(in, i+1, r, pre, lp+cnt+1, rp);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return build(B, 0, (int)B.size() - 1, A, 0, (int)A.size() - 1);
}
```
