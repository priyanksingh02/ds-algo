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

```cpp

string add(string s) {
    reverse(s.begin(), s.end());
    string ans;
    int carry = 1;
    int i = 0;
    while(i < s.size() or carry) {
        int sum = carry;
        if(i < s.size()) {
            sum += s[i++] - '0';
        }
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string convert(const string & A) {
    string ans = A;
    int l = A.size()/2;
    int n = A.size();
    for(int i = 0; i < l; ++i) {
        ans[n-1-i] = ans[i];
    }
    return ans;
}

string Solution::solve(string A) {
    auto cA = convert(A);
    if(cA > A)
        return cA;
    int l = (A.size()+1)/2;
    auto str = add({A.begin(), A.begin()+l});
    // cout << str << endl;
    if(str.size() > l) {
        string ans (A.size() + 1, '0');
        ans.front() = '1';
        ans.back() = '1';
        return ans;
    }
    string ans = A;
    int n = (int)ans.size() -1;
    for(int i=0; i < str.size(); ++i) {
        ans[i] = str[i];
        ans[n-i] = str[i];
    }
    return ans;
}
```
