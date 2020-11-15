```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(int &x: num)
        cin >> x;
    vector<int> right_min(n);
    int cur = INT_MAX;
    for(int i = n- 1; i>= 0; --i) {
        right_min[i] = cur;
        cur = min(cur, num[i]);
    }
    if(n == 0)
        return -1;
    int left_max = num[0];
    for(int i = 1; i + 1 < n; ++i) {
        if(num[i] >= left_max && num[i] <= right_min[i])
            return num[i];
        left_max = max(left_max, num[i]);
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
```
