```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int &x: nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        int ans = 1e9 + 7;
        for(int i = 1; i < n; ++i) {
            ans = min(ans, nums[i]^nums[i-1]);
        }
        cout << ans << '\n';
    }
}
```
