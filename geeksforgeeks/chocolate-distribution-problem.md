```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<long> num(n);
        for(long &x: num)
            cin >> x;
        cin >> m;
        sort(num.begin(), num.end());
        long ans = LONG_MAX;
        for(int i = 0;i + m - 1< n; ++i) {
            ans = min(ans, num[i+m-1] - num[i]);
        }
        cout << ans << '\n';
    }
}
```

