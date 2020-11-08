```cpp
#include <bits/stdc++.h>
using namespace std;

// f -> floors
int trial(int eggs, int f, vector<vector<int>> & dp) {
    if(eggs == 1)
        return f;
    if(f == 1)
        return 1;
    if(f <= 0)
        return 0;
    if(dp[eggs][f] != -1)
        return dp[eggs][f];
    int cur = 1e9;
    for(int k = 1; k <= f; ++k) {
        cur = min(cur, max(trial(eggs-1, k-1, dp),trial(eggs, f-k, dp)));
    }
    dp[eggs][f] = cur+1;
    return dp[eggs][f];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, eggs;
        cin >> eggs >> n;
        vector<vector<int>> dp(eggs+1, vector<int>(n+1, -1));
        cout << trial(eggs, n, dp) << "\n";
    }
}
```

