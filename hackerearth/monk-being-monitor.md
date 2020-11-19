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
        vector<int> v(n);
        for(int &x: v)
            cin >> x;
        map<int,int> m;
        for(int &x: v) {
            m[x]++;
        }
        vector<int> freq;
        for(auto &x: m) {
           freq.push_back(x.second);
        }
        int minelem = 1e7;
        int ans = 0;
        for(int i = 0; i < freq.size(); ++i) {
            minelem = min(minelem, freq[i]);
            ans = max(ans, freq[i] - minelem);
        }
        cout << (!ans?-1:ans) << '\n';
    }
}
```
