```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int m ,n ;
        m = a.size();
        n = b.size();
        vector<vector<int>> lcs(m+1, vector<int> (n+1, 0));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(a[i-1] == b[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else
                    lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
        cout << m + n - lcs[m][n] << '\n';
    }
}

```
