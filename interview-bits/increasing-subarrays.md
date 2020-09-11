```cpp

int Solution::cntInc(vector<int> &A) {
    int ans = 0;
    const int mod = 1e9 + 7;
    int count = 1;
    for(int i = 1; i < A.size(); ++i) {
        if(A[i] > A[i-1]) {
            ++count;
        }
        else {
            ans += ((count)*(count+1)/2)%mod;
            count = 1;
        }
    }
    ans += ((count)*(count+1)/2)%mod;
    return ans;
}
```
