```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int m, n;
    cin >> m >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(m +1, vector<int> (n + 1, 0));
    int maxlen = 0;
    for(int i = 1; i <= m ; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = 0;
            }
            maxlen = max(dp[i][j], maxlen);
        }
    }
    return maxlen;
}


int main() {
    int t;
    cin >>t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```

