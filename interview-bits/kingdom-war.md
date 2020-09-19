Idea: Maximum submatrix which include last element of matrix A (largest strength)
```cpp

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = m-1; i >= 0; --i) {
        for(int j = n-1; j >= 0; --j) {
            dp[i][j] = A[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}

```
Idea: Convert the problem from 2D to 1D
```cpp
int sum(const vector<int> & r) {
    int ans = INT_MIN;
    int sum = 0;
    for(int i = (int)r.size()-1; i>= 0; --i) {
        sum += r[i];
        ans = max(ans, sum);
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int ans = INT_MIN;
    for(int i = 0; i < m; ++i) {
        vector<int> row (n, 0);
        for(int j = i; j < m; ++j) {
            for(int k = 0; k < n; ++k) {
                row[k] += A[j][k];
            }
            ans = max(ans, sum(row));
        }
    }
    return ans;
}
```
