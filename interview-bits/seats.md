```cpp
// jump towards median
// take into account numbers present between current number and median
// decide the jump accordingly
int Solution::seats(string A) {
    const int mod = 1e7 + 3;
    vector<int> pos;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == 'x')
            pos.push_back(i);
    }
    if(pos.empty())
        return 0;
    int n = pos.size();
    int median = pos[n/2];
    int mpos = n/2;
    int ans = 0;
    for(int i= 0; i < mpos; ++i) {
        int jump = median - pos[i] - 1 - (mpos - i - 1);
        ans = (ans + jump)%mod;
    }
    for(int i = mpos + 1; i < n; ++i) {
        int jump = pos[i] - median - 1 - (i - mpos - 1);
        ans = (ans + jump)%mod;
    }
    return ans;
}

```
