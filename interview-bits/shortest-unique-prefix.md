```cpp

struct node {
    int cnt = 0;
    unordered_map<char, node*> child;
};

void insert(node * root, const string & s) {
    for(char c: s) {
        if(!root->child.count(c))
            root->child[c] = new node();
        root = root->child[c];
        root->cnt++;
    }
}

string pref(node * root, const string & s) {
    int k = 0;
    for(char c: s) {
        root = root->child[c];
        if(root->cnt == 1)
            break;
        k++;
    }
    return s.substr(0, k+1);
}

vector<string> Solution::prefix(vector<string> &A) {
    node * root = new node();
    for(auto & word: A) {
        insert(root, word);   
    }
    vector<string> ans;
    for(auto & word: A) {
        ans.emplace_back(pref(root, word));
    }
    return ans;
}

```
```cpp

struct node {
    int count;
    vector<node *> chars;
    node(): count(0), chars(vector<node *>(26, nullptr)) {}
};

void insert(node * root, const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        if(!root->chars[pos])
            root->chars[pos] = new node();
        root = root->chars[pos];
        root->count++;
    }
}

string search(node * root, const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        root = root->chars[pos];
        if(root->count == 1)
            return s.substr(0,i+1);
    }
    return "";
}

vector<string> Solution::prefix(vector<string> &A) {
    node * root = new node();
    for(auto & s: A) {
        insert(root, s);
    }
    vector<string> ans;
    for(auto & s: A) {
        ans.push_back(search(root, s));
    }
    return ans;
}

```
```cpp
struct node {
    int count;
    vector<node *> chars;
    node(): count(0), chars(vector<node *>(26, nullptr)) {}
};

void insert(string & s, node * root) {
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        if(root->chars[pos] == nullptr) {
            root->chars[pos] = new node ();
        }
        root->count++;
        root = root->chars[pos];
    }
    root->count++;
}

string search(node * root, string & word) {
    for(int i = 0; i < word.size(); ++i) {
        int pos = word[i] - 'a';
        if(root->chars[pos]->count == 1)
            return word.substr(0, i+1);
        root = root->chars[pos];
    }
    return word;
}

// void search(node * root, string & prefix, vector<string> &ans) {
//     for(int i = 0; i < 26; ++i) {
//         if(root->chars[i]) {
//             if(root->chars[i]->count == 1) {
//                 ans.push_back(prefix + char(i+'a'));
//             }
//             else {
//                 prefix += char(i + 'a');
//                 search(root->chars[i], prefix, ans);
//                 prefix.pop_back();
//             }
//         }
//     }
// }

vector<string> Solution::prefix(vector<string> &A) {
    node * root = new node ();
    for(auto & s: A) {
        insert(s, root);
    }
    vector<string> ans;
    for(auto & s: A) {
        ans.push_back(search(root, s));
    }
    // string prefix;
    // search(root, prefix, ans);
    return ans;
}
```
