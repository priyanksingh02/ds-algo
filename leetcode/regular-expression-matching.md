```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= p.size(); ++i) {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-2];
        }
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 1; j <= p.size(); ++j) {
                if(s[i-1] == p[j-1] or p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    if(s[i-1] == p[j-2] or p[j-2] == '.')
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
```

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int test = false;
        // test for invalid pattern string
        for(int i = 0; i < m; ++i) {
            if(p[i] == '*') {
                if(!test)
                    return false;
                test = false;
            }
            else {
                test = true;
            }
        }
        // actual algo starts here
        vector<vector<bool>> dp (m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i) {
            if(p[i-1] == '*') {
                assert(i-2 >= 0);
                dp[i][0] = dp[i-2][0];
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s[j-1] == p[i-1] or p[i-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    if(p[i-2] == s[j-1] or p[i-2] == '.') {
                        dp[i][j] = dp[i][j-1] || dp[i-2][j];
                    }
                    else {
                        dp[i][j] = dp[i-2][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
```
