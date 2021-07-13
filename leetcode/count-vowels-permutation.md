```cpp
#include <numeric>
const int M = 1000000000 + 7;
class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 0)
            return 0;
        map<char, int> idx {{'a',0}, {'e',1}, {'i', 2}, {'o', 3}, {'u', 4}};
        vector<vector<int>> dp (n, vector<int> (5, 0));
        for(int i = 0; i < 5; ++i) {
            dp[0][i] = 1;
        }
        // count creation based on previous length
        for(int i = 1; i < n; ++i) {
            dp[i][idx['a']] = ((dp[i-1][idx['e']] + dp[i-1][idx['i']])%M + dp[i-1][idx['u']])%M;
            dp[i][idx['e']] = (dp[i-1][idx['a']] + dp[i-1][idx['i']])%M;
            dp[i][idx['i']] = (dp[i-1][idx['e']] + dp[i-1][idx['o']])%M;
            dp[i][idx['o']] = (dp[i-1][idx['i']])%M;
            dp[i][idx['u']] = (dp[i-1][idx['i']] + dp[i-1][idx['o']])%M;
        }
        return accumulate(dp.back().begin(), dp.back().end(), 0, [](int a, int b){
            return (a+b)%M;
        });
    }
};

```
