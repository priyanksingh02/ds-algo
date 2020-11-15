# Subarray with given sum
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while(t--) {
        int n, sum;
        cin >> n >> sum;
        vector<long> nums(n);
        for(auto & x: nums)
            cin >> x;
        int i = 0, j = 0;
        long cur = 0;
        bool found = false;
        while(j < (int)nums.size() and !found) {
            cur += nums[j];
            while(cur > sum && i <= j) {
                cur -= nums[i];
                i++;
            }
            if(cur == sum) {
                found = true;
                cout << i+1 << " " << j+1 << "\n";
            }
            j++;
        }
        if(!found) {
            puts("-1");
        }
    }
}
```

