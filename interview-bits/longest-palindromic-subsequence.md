```cpp
vector<vector<int>> dp;

int count(const string & A, int i, int j) {
    if(i > j)
        return 0;
    if(i == j) {
        dp[i][j] = 1;
        return 1;
    }
    if(dp[i][j] != -1)
        return dp[i][j];

    if(A[i] == A[j])
        dp[i][j] = max({2 + count(A, i+1, j-1), count(A, i, j-1), count(A, i+1, j)});
    else 
        dp[i][j] = max(count(A, i, j-1), count(A,i+1, j));
    return dp[i][j];
}

int Solution::solve(string A) {
    int n = A.size();
    dp.clear();
    dp.resize(n, vector<int> (n, -1));
    int ans = count(A, 0, n-1);
    return ans;
}
```
