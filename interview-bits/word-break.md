## Word Break
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

int Solution::wordBreak(string A, vector<string> &B) {
    vector<bool> dp (A.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= A.size(); ++i) {
        for(auto & s: B) {
            int len = s.size();
            int pos = i - len;
            if(pos < 0)
                continue;
            if(dp[pos] && A.substr(pos, len) == s) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}
```

```cpp
struct node {
    bool leaf = false;
    unordered_map<char, node*> child;
};

void insert(node * root, const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        if(root->child.count(s[i]) == 0)
            root->child[s[i]] = new node();
        root = root->child[s[i]];
    }
    root->leaf = true;
}

int Solution::wordBreak(string A, vector<string> &B) {
    node * root = new node();
    for(auto & s: B) {
        insert(root, s);
    }
    vector<bool> dp (A.size() + 1, false);
    dp[0] = true;
    for(int i = 0; i < A.size(); ++i) {
        if(dp[i]) {
            node * iter = root;
            int k = 0;
            while(i+k < A.size() && iter->child.count(A[i+k])) {
                iter = iter->child[A[i+k]];
                if(iter->leaf)
                    dp[i+k+1] = true;
                k++;
            }
        }
    }
    return dp.back();
}
```
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
## Word Break II

```cpp

struct node {
    bool isleaf;
    unordered_map<char, node*> chars;
    node(): isleaf(false) {}
};

void insert(const string & s, node * root) {
    for(int i = 0; i < s.size(); ++i) {
        if(root->chars.find(s[i]) == root->chars.end())
            root->chars[s[i]] = new node ();
        root = root->chars[s[i]];
    }
    root->isleaf = true;
}

void search(const string & s, int pos, vector<vector<string>> & ans, vector<string> & cur, node * r) {
    if(pos == s.size()) {
        ans.push_back(cur);
        return ;
    }
    node * root = r;
    for(int i = pos; i < s.size(); ++i) {
        if(root->chars.find(s[i]) != root->chars.end()) {
            root = root->chars[s[i]];
            if(root->isleaf) {
                cur.push_back(s.substr(pos, i - pos + 1));
                search(s, i+1, ans, cur, r);
                cur.pop_back();
            }
        }
        else 
            break;
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    if(A.empty() || B.empty())
        return {};
    node * root = new node();
    for(auto & b: B)
        insert(b, root);
    vector<vector<string>> temp_ans;
    vector<string> row;
    search(A, 0, temp_ans, row, root);
    vector<string> ans;
    for(auto & v: temp_ans) {
        string merge;
        for(auto & s: v) {
            if(!merge.empty())
                merge.push_back(' ');
            merge += s;
        }
        ans.push_back(merge);
    }
    return ans;
}

```

```cpp
struct node {
    bool isleaf;
    vector<node *> alphabet;
    node(): isleaf(false), alphabet(vector<node *> (26,nullptr)) {}
};

void insert(string & s, node * root) {
    node * t = root;
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        if(t->alphabet[pos] == nullptr)
            t->alphabet[pos] = new node();
        t = t->alphabet[pos];
    }
    t->isleaf = true;
}

void f(string & src, int pos, node * trie, string cur, vector<string> & ans) {
    // cout << pos << " " << cur << endl;
    node * t = trie;
    for(int i = pos; i < src.size(); ++i) {
        int ch = src[i] - 'a';
        if(t->alphabet[ch] == nullptr)
            break;
        if(t->alphabet[ch]->isleaf) {
            string word;
            if(!cur.empty())
                word += " ";
            word += src.substr(pos, i - pos + 1);
            // cout << "cur is " << cur << endl;
            if(i + 1 == src.size()) {
                // cout << "pushing " << cur << endl;
                ans.push_back(cur + word);
            }
            else {
                f(src, i + 1, trie, cur + word, ans);
            }
        }
        t = t->alphabet[ch];
    }
}

// void print(node * root) {
//     for(int i = 0; i < 26; ++i) {
//         if(root->alphabet[i]) {
//             cout << char('a'+i);
//             if(root->alphabet[i]->isleaf)
//                 cout << " leaf";
//             cout << endl;
//             print(root->alphabet[i]);
//         }
//     }
// }

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector<string> ans;
    node * root = new node();
    for(auto & x: B) {
        insert(x, root);
    }
    // cout << "tree" << endl;
    // print(root);
    f(A, 0, root, "", ans);
    return ans;
}

```

