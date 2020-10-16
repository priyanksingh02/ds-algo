```cpp

int cal(const vector<int>& arr, int low, int high, 
    vector<vector<int>> & dp, vector<int> & prefix) {
        assert(low <= high);
        if(low == high) {
            return 0;
        }
        if(dp[low][high] != -1) {
            return dp[low][high];
        }
        int ans = INT_MAX;
        int cur = prefix[high+1] - prefix[low];
        for(int i = low; i < high; ++i) {
            ans = min(ans, cal(arr, low, i, dp, prefix) + cal(arr, i+1, high, dp, prefix));
        }
        ans += cur; // add current cost;
        return dp[low][high] = ans;
    }

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp (n, vector<int> (n, -1));
    vector<int> prefix(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + A[i-1];
    }
    return cal(A, 0, n-1, dp, prefix);
}
```
