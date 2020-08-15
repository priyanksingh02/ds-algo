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
