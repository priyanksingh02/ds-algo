
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        int n = input.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxlen = 0;
        int idx = -1;
        for(int i= n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(input[i] == input[j]) {
                    if(i + 1 == j) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j]) {
                    if(maxlen < j - i + 1) {
                        maxlen = j - i + 1;
                        idx = i;
                    }
                    else if(maxlen == j-i+1) {
                        idx = i;
                    }
                }
            }
        }
        cout << input.substr(idx, maxlen) << "\n";
    }
}
```
