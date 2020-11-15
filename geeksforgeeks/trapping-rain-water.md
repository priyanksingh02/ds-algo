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
        for(int &x: nums) {
            cin >> x;
        }
        vector<int> left(n), right(n);
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            left[i] = max(left[i], cur);
            cur = max(cur, nums[i]);
        }
        cur = 0;
        for(int i = n - 1; i >= 0; --i) {
            right[i] = max(right[i], cur);
            cur = max(cur, nums[i]);
        }
        long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += max(0, min(left[i], right[i]) - nums[i]);
        }
        cout << ans << "\n";
    }
}
```

