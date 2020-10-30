# Binary Tree Paths(Easy)
```cpp
class Solution {
    vector<string> ans;
public:
    string convert(vector<int> & t) {
        string ans ;
        for(int i =0; i < t.size(); ++i) {
            if(!ans.empty())
                ans += "->";
            ans += to_string(t[i]);
        }
        return ans;
    }
    void travel(TreeNode * root, vector<int> & t) {
        if(!root)
            return ;
        t.push_back(root->val);
        if(!root->left and !root->right) {
            ans.push_back(convert(t));
        }
        else {
            travel(root->left, t);
            travel(root->right, t);
        }
        t.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> t;
        travel(root, t);
        return ans;
    }
};
```

