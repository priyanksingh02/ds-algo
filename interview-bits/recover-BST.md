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
void f(TreeNode * root, int & prev, vector<pair<int, int>> & ans) {
    if(root) {
        f(root->left, prev, ans);
        if(root->val < prev) {
            ans.push_back({root->val, prev});
        }
        prev = root->val;
        f(root->right, prev,ans);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    int prev = 0;
    vector<pair<int,int>> v;
    f(A, prev, v);
    vector<int> ans;
    if(v.size() == 1) {
        ans.push_back(v.front().first);
        ans.push_back(v.front().second);
        return ans;
    }
    auto it = v.rbegin();
    ans.push_back(min(it->first,it->second));
    ++it;
    ans.push_back(max(it->first,it->second));
    return ans;
}
```

```cpp
void inorder(TreeNode * root, int & prev, vector<int> & ans) {
    if(root) {
        inorder(root->left, prev, ans);
        if(root->val < prev) {
            if(ans.empty()) {
                ans.push_back(prev);
                ans.push_back(root->val);
            }
            else {
                ans.pop_back();
                ans.push_back(root->val);
            }
        }
        prev = root->val;
        inorder(root->right, prev, ans);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    int prev = 0;
    inorder(A, prev, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
```
