```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            if(s[i] != '0')
                dp[i+1] += dp[i];
            if(i > 0 && s[i-1] != '0' && stoi(s.substr(i-1,2)) <= 26)
                dp[i+1] += dp[i-1];
        }
        return dp[n];
    }
};
```
