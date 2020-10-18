```cpp
vector<vector<int>> ans;
int target;
void path(TreeNode* root, int sum, vector<int>& row) {
    if(root) {
        row.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right && sum == target) {
            ans.push_back(row);
        }
        if(root->left)
            path(root->left, sum, row);
        if(root->right)
            path(root->right, sum, row);
        row.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    target = B;
    ans.clear();
    vector<int> row;
    path(A, 0, row);
    return ans;
}
```
