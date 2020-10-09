```cpp

string divide(const string & a) {
    string ans;
    int carry = 0;
    for(int i = 0; i < a.size(); ++i) {
        carry = carry * 10 + a[i] - '0';
        ans.push_back(carry/2 + '0');
        carry = carry % 2;
    }
    int i = 0;
    while(i < ans.size() && ans[i] == '0')
        i++;
    return ans.substr(i);
}

bool odd(const string & a) {
    assert(!a.empty());
    int digit = a.back() - '0';
    return digit & 1;
}

int Solution::power(string A) {
    int i = 0; 
    while(i < A.size() && A[i] == '0')
        i++;
    if(A.empty())
        return false;
    A = A.substr(i);
    if(A.size() == 1 && stoi(A) == 1)
        return false;
    while(A.size() > 1 || stoi(A) > 1) {
        // cout << A << endl;
        if(odd(A))
            return false;
        A = divide(A);
    }
    return true;
}
```
