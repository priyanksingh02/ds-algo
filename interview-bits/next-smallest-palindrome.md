```cpp

string addone(string s) {
    string ans;
    int carry = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
        ans.push_back((s[i] - '0' + carry)%10 + '0');
        carry = (s[i] - '0' + carry)/10;
    }
    if(carry)
        ans.push_back(carry + '0');
    reverse(ans.begin(),ans.end());
    return ans;
}

string pal(string s, int sz) {
    string ans = s;
    int lastpos = s.size() -1;
    int lim = s.size()/2;
    for(int i = 0; i < lim; ++i) {
        ans[lastpos - i] = ans[i];
    }
    if(ans.size() > sz || ans >= s) {
        return ans;
    }
    string prefix;
    if(s.size() & 1) {
        prefix = addone(s.substr(0, lim + 1));
    }
    else {
        prefix = addone(s.substr(0, lim));
    }
    for(int i = 0; i < lim; ++i) {
        ans[i] = prefix[i];
        ans[lastpos - i] = prefix[i];
    }
    if(s.size() & 1)
        ans[lim] = prefix.back();
    return ans;
}

string Solution::solve(string A) {
    return pal(addone(A),A.size());
}
```
