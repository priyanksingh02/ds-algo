### Recursive
```cpp

struct node {
    bool isleaf;
    vector<node *> chars;
    node(): isleaf(false), chars(vector<node*>(26, nullptr)) {}
};

void insert(string & s, node * root) {
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        if(root->chars[pos] == nullptr)
            root->chars[pos] = new node();
        root = root->chars[pos];
    }   
    root->isleaf = true;
}

bool check(string & src, int pos, node * root) {
    node * trie = root;
    for(int i = pos; i < src.size(); ++i) {
        int p = src[i] - 'a';
        if(trie->chars[p] == nullptr)
            return false;
        trie = trie->chars[p];
        if(trie->isleaf) {
            if(i + 1 == src.size())
                return true;
            if(check(src, i + 1, root))
                return true;
        }
    }
    return false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    node * root = new node();
    for(auto & x: B) {
        insert(x, root);
    }
    return check(A, 0, root);
}

```
### Iterative

```cpp

struct node {
    bool isleaf;
    vector<node *> chars;
    node(): isleaf(false), chars(vector<node*>(26,nullptr)) {}
};

void insert(string & s, node * root) {
    for(int i = 0; i< s.size(); ++i) {
        int pos = s[i] - 'a';
        if(root->chars[pos] == nullptr)
            root->chars[pos] = new node();
        root = root->chars[pos];
    }
    root->isleaf = true;
}

int Solution::wordBreak(string A, vector<string> &B) {
    vector<bool> dp (A.size() + 1, false);
    node * root = new node();
    for(auto & x: B) {
        insert(x, root);
    }
    dp[0] = true;
    for(int i = 0; i < A.size(); ++i) {
        if(dp[i]) {
            node * r = root;
            for(int j = i; j < A.size(); ++j) {
                int pos = A[j] - 'a';
                if(r->chars[pos]) {
                    r = r->chars[pos];
                    if(r->isleaf)
                        dp[j+1] = true;
                }
                else {
                    break;
                }
            }
        }
    }
    return dp.back();
}
```
