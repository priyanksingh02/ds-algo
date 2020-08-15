```cpp

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int R = A.size();
    int C = A.front().size();
    vector<vector<int>> dp (R, vector<int> (C,0));
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(A[i][j] == 1)
                dp[i][j] = 0;
            else if(i == 0 and j == 0)
                dp[i][j] = 1;
            else { 
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j-1];
            }
                
        }
    }
    return dp[R-1][C-1];
}

```
