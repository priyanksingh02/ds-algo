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
        int grid[n][n];
        for(int i = 0;i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = i; k < n; ++k) {
                    for(int l = j; l < n; ++l) {
                        if(grid[i][j] > grid[k][l])
                            ++ans;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
```

