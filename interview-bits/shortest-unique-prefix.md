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
