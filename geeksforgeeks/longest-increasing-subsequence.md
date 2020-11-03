Time: O(n logn)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &x: nums)
            cin >> x;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(ans.empty() or ans.back() < nums[i])
                ans.push_back(nums[i]);
            else {
                auto iter = lower_bound(ans.begin(), ans.end(), nums[i]);
                assert(iter != ans.end());
                *iter = nums[i];
            }
        }
        cout << ans.size() << "\n";
    }
    return 0;
}
```
Time: O(n^2)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &x: nums)
            cin >> x;
        vector<int> dp(n, 1);
        int maxlen = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxlen = max(dp[i], maxlen);
        }
        cout << maxlen << "\n";
    }
    return 0;
}

```

