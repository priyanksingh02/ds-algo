```cpp
int Solution::solve(vector<int> &A, int B, int C) {
    if(A.empty())
        return 0;
    string limit = to_string(C);
    // cout << "limit is " << limit << endl;
    int len = limit.size();
    int count = A.size();
    bool zero = A[0] == 0;
    // cout << "zero is " << zero << endl;
    if(len < B) {
        return 0;
    }
    if(len > B) {
        if(zero && B > 1) {
            return (count - 1)*pow(count, B - 1);
        }
        else
            return pow(count, B);
    }
    int ans = 0;
    bool done = false;
    for(int i = 0; i < limit.size() && !done; ++i) {
        int less = lower_bound(A.begin(),A.end(),limit[i] - '0') - A.begin();
        if(less >= A.size() || A[less] + '0' != limit[i])
            done = true;
        // cout << "less returned " << less ;
        if(i == 0 && zero && i + 1 != len) {
            less--;
        }
        // cout << " .. after comp " << less << endl;
        ans += less * pow(count, len - i - 1);
    }
    return ans;
}
```
