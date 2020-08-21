```cpp

string add(string a, string b) {
    int carry = 0;
    int i = 0;
    int j = 0;
    string ans;
    while(i < a.size() || j < b.size() || carry) {
        int sum = carry;
        if(i < a.size()) {
            sum += a[i++] - '0';
        }
        if(j < b.size()) {
            sum += b[j++] - '0';
        }
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    return ans;
}

string mul(string a, char b) {
    b = b - '0';
    string ans;
    int carry = 0;
    for(int i = 0; i < a.size(); ++i) {
        int sum = (a[i]-'0')*b + carry;
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    while(carry) {
        ans.push_back(carry%10 + '0');
        carry /= 10;
    }
    return ans;
}

string Solution::multiply(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string ans = "0";
    for(int i = 0; i < A.size(); ++i) {
        ans = add(ans, string(i,'0') + mul(B, A[i]));
    }
    while(!ans.empty() && ans.back() == '0')
        ans.pop_back();
    if(ans.empty())
        return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}

```
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
