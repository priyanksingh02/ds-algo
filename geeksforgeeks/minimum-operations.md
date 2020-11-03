# Minimum Operations:
## DP
```cpp
class Solution
{
  public:
    int minOperation(int n)
    {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <=n; ++i) {
            if(i&1) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = min(dp[i-1], dp[i/2]) + 1;
            }
        }
        return dp.back();
    }
};
```

## Greedy
```cpp
class Solution
{
  public:
    int minOperation(int n)
    {
        int cnt = 0;
        while(n) {
            if(n&1) { // odd
                n -= 1;
            }
            else  // even
                n /= 2;
            ++cnt;
        }
        return cnt;
    }
};

```

