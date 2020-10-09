```cpp

string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int carry = 0;
    int i = 0, j = 0;
    string ans;
    while(i < A.size() or j < B.size() or carry) {
        int sum = carry;
        if(i < A.size()) {
            sum += A[i] - '0';
            i++;
        }
        if(j < B.size()) {
            sum += B[j] - '0';
            j++;
        }
        ans.push_back('0' + sum%2);
        carry = sum/2;
    }
    while(!ans.empty() and ans.back() == '0')
        ans.pop_back();
    if(ans.empty())
        return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}
```
