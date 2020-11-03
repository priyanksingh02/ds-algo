```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, W;
        cin >> n >> W;
        vector<int> w(n), val(n);
        for(auto &x: val)
            cin >> x;
        for(auto &x: w)
            cin >> x;
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j= 1; j <= W; ++j) {
                if(w[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + val[i-1]);
                }
            }
        }
        cout << dp[n][W] << "\n";
    }
}
```

