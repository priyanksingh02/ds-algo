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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(!A)
        return {};
    vector<vector<int>> ans;
    vector<int> row;
    bool d = true; // direction
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()) {
        int k = q.size();
        for(int i = 0; i < k; ++i) {
            A = q.front();
            q.pop();
            row.push_back(A->val);
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        if(!d)
            reverse(row.begin(), row.end());
        d ^= true; // flip direction
        ans.push_back(row);
        row.clear();
    }
    return ans;
}
```
