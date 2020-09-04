```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        vector<int> longest(s.size(), 0);
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == ')') {
                int pos = i - longest[i-1] - 1;
                if(pos >= 0 && s[pos] == '(') {
                    longest[i] = longest[i-1] + 2 + ((pos - 1>= 0)?longest[pos-1]:0);
                    maxlen = max(maxlen, longest[i]);
                }
            }
        }
        return maxlen;
    }
};

```
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        for(int i = 0; i < dp.size(); ++i) {
            if(s[i] == ')') {
                if(i > 0 && s[i-1] == '(') {
                    dp[i] = 2 + ((i-2 >= 0)?dp[i-2]:0);
                }
                else if(i > 0 && s[i-1] == ')') {
                    int pos = i - dp[i-1] - 1;
                    if(pos >= 0 && s[pos] == '(') {
                        dp[i] = 2 + dp[i-1] + ((pos-1 >= 0)?dp[pos-1]:0);
                    }
                }
            }
        }
        int ans = 0;
        for(auto & x: dp){
            ans = max(x, ans);
        }    
        return ans;
    }
};
```
