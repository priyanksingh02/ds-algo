```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans;
        q.push(root);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(root) {
                q.push(root->left);
                q.push(root->right);
                ans += to_string(root->val) + " ";
            }
            else {
                ans += "N ";
            }
        }
        ans.pop_back(); // last space
        return ans;
    }
    
    TreeNode * get(string& val) {
        if(val == "N")
            return nullptr;
        else
            return new TreeNode(stoi(val));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s {data};
        string val;
        s >> val;
        TreeNode * root = get(val);
        if(!root)
            return root;
        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()) {
            TreeNode * t = q.front(); q.pop();
            s >> val;
            t->left = get(val);
            if(t->left)
                q.push(t->left);
            s >> val;
            t->right = get(val);
            if(t->right)
                q.push(t->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```
