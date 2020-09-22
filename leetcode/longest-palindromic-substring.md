```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int posi = 0, maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(s[i] == s[j]) {
                    if(i+1 == j) 
                        dp[i][j] = true; // when j-1 > i+1
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j] = false;
                if(dp[i][j] && j - i + 1 >= maxlen) {
                    maxlen = j - i + 1;
                    posi = i;
                }
            }
        }
        return s.substr(posi, maxlen);
    }
};
```
