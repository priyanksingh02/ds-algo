```cpp
string removeDups(string S) 
{
    set<char> seen;
    string ans;
    for(int i = 0;i < S.size(); ++i) {
        if(!seen.count(tolower(S[i]))) {
            seen.insert(tolower(S[i]));
            ans.push_back(S[i]);
        }
    }
    return ans;
}

```

