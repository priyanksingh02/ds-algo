```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
```
Recursive:
```cpp
class Solution {
    vector<int> cache;
    
public:
    Solution() {
        cache.resize(20, -1);
    }
    int numTrees(int n) {
        if(n == 1 | n == 0)
            return 1;
        if(cache[n] != -1)
            return cache[n];
        int count = 0;
        for(int i = 0; i < n; ++i) {
            count += numTrees(i)*numTrees(n - 1 - i);
        }
        return cache[n] = count;
    }
};
```

# Unique Binary Search Trees II

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if(start > end) {
            return {nullptr};
        }
        vector<TreeNode*> ans;
        for(int i = start; i <= end; ++i) {
            auto left = build(start, i -1 );
            auto right = build(i+1, end);
            for(TreeNode * l : left) {
                for(TreeNode * r: right) {
                    TreeNode * root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return build(1, n);
    }
};

```
