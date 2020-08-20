```cpp
// strings stored in reverse - final ans needs to be reversed
// add
string add(string a, string b) {
    string ans;
    int len = max(a.size(),b.size());
    a += string(len - (int)a.size(), '0');
    b += string(len - (int)b.size(), '0');
    assert(a.size() == b.size());
    int carry = 0;
    for(int i = 0; i < a.size(); ++i) {
        int sum = (a[i]- '0') + (b[i] - '0') + carry;
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if(carry) {
        ans.push_back(carry + '0');
    }
    return ans;
}
// multiply with digit
string mul(string s, char a) {
    if(a == '0')
        return "0";
    int carry = 0;
    string ans;
    for(int i = 0; i < s.size(); ++i) {
        int prod = (s[i]-'0')*(a - '0');
        prod += carry;
        ans.push_back(prod%10 + '0');
        carry = prod/10;
    }
    while(carry) {
        ans.push_back(carry%10 + '0');
        carry /= 10;
    }
    return ans;
}

string Solution::multiply(string A, string B) {
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    string ans = "0";
    for(int i = 0; i < B.size(); ++i) {
        ans = add(string(i, '0') + mul(A,B[i]), ans);
    }
    //remove leading zeroes
    while(!ans.empty() and ans.back() == '0')
        ans.pop_back();
    if(ans.empty())
        ans = "0";
    reverse(ans.begin(),ans.end());
    return ans;
}
```
