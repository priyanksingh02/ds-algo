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
        for(auto & x: nums)
            cin >> x;
        int can_reach, will_reach;
        can_reach = will_reach = 0;
        int steps = 0;
        for(int i = 0; i < n; ++i) {
            can_reach = max(can_reach, i + nums[i]);
            if(i + 1 == n) {
                cout << steps << "\n";
                break;
            }
            if(i == will_reach) {
                if(can_reach == will_reach) {
                    puts("-1");
                    break; // can't jump further
                }
                will_reach = can_reach;
                ++steps;
            }
        }
    }
}
```

