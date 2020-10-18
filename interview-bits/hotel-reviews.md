```cpp

vector<string> extract(const string & s) {
    int i  = 0;
    vector<string> ans;
    while(i < s.size()) {
        auto iter = s.find('_',i);
        if(iter != string::npos) {
            ans.push_back(s.substr(i, iter-i));
            i = iter + 1;
        }
        else {
            break;
        }
    }
    if(i < s.size())
        ans.push_back(s.substr(i));
    return ans;
}

struct node {
    bool leaf = false;
    unordered_map<char, node*> child;
};

void insert(node * root, const string & s) {
    for(char c: s) {
        if(root->child.count(c) == 0)
            root->child[c] = new node();
        root = root->child[c];
    }
    root->leaf = true;
}

bool search(node * root, const string & s) {
    for(char c: s) {
        if(root->child.count(c)) {
            root = root->child[c];
        }
        else
            return false;
    }
    return root->leaf;
}

int gwords(vector<string> vs, node * root) {
    int cnt = 0;
    for(auto & word: vs) {
        if(search(root, word))
            ++cnt;
    }
    return cnt;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    node * root = new node();
    for(auto & s: extract(A)) {
        insert(root, s);
    }
    vector<pair<int,int>> idx;
    for(int i = 0; i < B.size(); ++i) {
        int cnt = gwords(extract(B[i]), root);
        idx.push_back({cnt, i});
    }
    sort(idx.begin(), idx.end(), [](auto & a, auto & b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    vector<int> ans;
    for(auto& x: idx)
        ans.emplace_back(x.second);
    return ans;
}
```
