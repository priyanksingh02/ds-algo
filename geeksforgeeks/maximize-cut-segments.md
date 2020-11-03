```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    vector<int> segment(3);
    cin >> n;
    for(int &x: segment)
        cin >> x;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = segment[i]; j <= n; ++j) {
            if(dp[j - segment[i]] >= 0)
                dp[j] = max(dp[j], dp[j-segment[i]] + 1);
        }
    }
    return dp[n];
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
```

