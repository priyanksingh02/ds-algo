```cpp
int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        int light = -1;
        for(int j = max(0, i-B+1); j < A.size() && j <= i + B - 1; ++j) {
            if(A[j]) {
                light = j;
            }
        }
        if(light == -1)
            return -1;
        ans++;
        i = light + B - 1;
    }
    return ans;
}
```
