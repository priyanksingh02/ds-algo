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
vector<int> Solution::solve(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        root = q.front(); q.pop();
        ans.push_back(root->val);
        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
    }
    return {ans.rbegin(), ans.rend()};
}
```

```cpp
vector<int> Solution::solve(TreeNode* A) {
    vector<vector<int>> tmp;
    vector<int> row;
    if(!A)
        return {};
    queue<TreeNode*> q;
    q.push(A);
    q.push(nullptr);
    while(!q.empty()) {
        A = q.front(); q.pop();
        if(A) {
            row.push_back(A->val);
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        else {
            tmp.push_back(row);
            row.clear();
            if(!q.empty())
                q.push(nullptr);
        }
    }
    reverse(tmp.begin(), tmp.end());
    vector<int> ans;
    for(auto & x: tmp) {
        for(auto & y: x)
            ans.emplace_back(y);
    }
    return ans;
}
```
