```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(vector<int> & v, int low, int high, int player) {
    if(low > high)
        return 0;
    if(dp[low][high] != -1)
        return dp[low][high];
    int amount;
    // player 1 will try to maximize his amount
    // player 2 will try to minimize player 1's amount
    if(player == 1) {
        amount = max(solve(v, low+1, high, 2) + v[low], solve(v, low, high-1, 2) + v[high]);
    }
    else {
        amount = min(solve(v, low+1, high, 1), solve(v, low, high - 1, 1));
    }
    return dp[low][high] = amount;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n ;
        cin >> n;
        vector<int> v (n);
        dp.clear();
        dp.resize(n, vector<int> (n, -1));
        for(int &x: v)
            cin >> x;
        cout << solve(v, 0, n-1, 1) << "\n";
    }
}
```

