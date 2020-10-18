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
int minidx, maxidx;
vector<vector<int>> ans;
void preorder(TreeNode * root, int idx) {
    if(root) {
        minidx = min(minidx, idx);
        maxidx = max(maxidx, idx);
        preorder(root->left, idx-1);
        preorder(root->right, idx+1);
    }
}

void fill(TreeNode * root) {
    queue<pair<TreeNode *,int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        root = p.first;
        int idx = p.second;
        ans[idx-minidx].push_back(root->val);
        if(root->left)
            q.push({root->left, idx-1});
        if(root->right)
            q.push({root->right, idx+1});
    }
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(!A)
        return {};
    minidx = 0;
    maxidx = 0;
    ans.clear();
    preorder(A, 0);
    int width = maxidx - minidx + 1;
    ans.resize(width);
    fill(A);
    return ans;
}
```
