```cpp
struct node {
    int val;
    int small;
    node* left;
    node* right;
    node(int v): val(v), small(0), left(nullptr), right(nullptr) {}
};

int insert(node * root, int key) {
    bool connected = false;
    int count = 0;
    while(!connected) {
        if(root->val >= key) {
            root->small++;
            if(root->left) {
                root = root->left;
            }
            else {
                root->left = new node(key);
                connected = true;
            }
        }
        else {
            count += root->small + 1;
            if(root->right)
                root = root->right;
            else {
                root->right = new node(key);
                connected = true;
            }
        }
    }
    return count;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty())
            return ans;
        ans.push_back(0);
        node * root = new node(nums.back());
        if(nums.size() == 1)
            return ans;
        for(int i = (int)nums.size() - 2; i >= 0; --i) {
            ans.push_back(insert(root, nums[i]));
        }
        return {ans.rbegin(), ans.rend()};
    }
};
```
