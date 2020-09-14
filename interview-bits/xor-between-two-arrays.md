```cpp
struct node {
    node* left = nullptr;
    node* right = nullptr;
};

#define MAX 31

void insert(node * root, int n) {
    for(int i = MAX; i >= 0; --i) {
        int bit = n & (1 <<i);
        if(bit) {
            if(!root->right)
                root->right = new node();
            root = root->right;
        }
        else {
            if(!root->left)
                root->left = new node();
            root = root->left;
        }
    }
}

int find(node * root, int n) {
    int ans = 0;
    for(int i = MAX; i >= 0; --i) {
        int bit = n & (1 <<i);
        // cout << n << " " << i << " bit = " << bit << endl;
        if(bit) {
            if(root->left) {
                ans += (1 << i);
                root = root->left;
            }
            else {
                root= root->right;
            }
        }
        else {
            if(root->right) {
                ans += (1 << i);
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }
    return ans;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    node * root = new node();
    for(auto & x: A) {
        insert(root, x);
    }
    int ans = 0;
    for(auto & x: B) {
        ans = max(ans, find(root, x));
    }
    return ans;
}
```
