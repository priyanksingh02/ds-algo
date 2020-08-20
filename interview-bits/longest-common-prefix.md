```cpp
 
struct node {
    bool isleaf;
    unordered_map<char, node *> chars;
    node(): isleaf(false) {}
};

void insert(string & s, node * root) {
    for(int i = 0; i < s.size(); ++i) {
        if(root->chars.count(s[i]) == 0) {
            root->chars[s[i]] = new node();
        }
        root = root->chars[s[i]];
    }
    root->isleaf = true;
}

string lcp(node * root) {
    string ans;
    while(root->chars.size() == 1 && !(root->isleaf)) {
        char letter = root->chars.begin()->first;
        ans += letter;
        root = root->chars.begin()->second;
    }
    return ans;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    node * root = new node();
    for(auto & x: A) {
        insert(x, root);
    }
    return lcp(root);
}
```

Sorting time : O(nklogn) where k is length of string

```cpp

string Solution::longestCommonPrefix(vector<string> &A) 
{
    string s;
    //sorting the strings lexicographically 
    sort(A.begin(),A.end());
    int m,n;
    m=A.size()-1;
    n=min(A[0].length(),A[m].length());
    int i=0;
    //first and last string will be most dissimilar thus finding common charcters in these
    while(i<n && A[0][i]==A[m][i])
    {
        s+=A[0][i];
        i++;
    }
    return s;
}
```
