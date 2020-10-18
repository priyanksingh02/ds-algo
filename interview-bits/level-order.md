```cpp
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(!A) return ans;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()) {
        int k = q.size();
        vector<int> row;
        for(int i = 0; i< k; ++i) {
            A = q.front();
            q.pop();
            row.push_back(A->val);
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        ans.push_back(row);
    }
    return ans;
}
```
```cpp

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(!A) return {};
    queue<TreeNode *> q;
    q.push(A);
    q.push(nullptr);
    vector<vector<int>> ans;
    vector<int> cur;
    while(!q.empty()) {
        TreeNode * p = q.front(); q.pop();
        if(p) {
            cur.push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        else {
            ans.push_back(move(cur));
            cur.clear();
            if(!q.empty())
                q.push(nullptr);
        }
    }
    return ans;
}
```

