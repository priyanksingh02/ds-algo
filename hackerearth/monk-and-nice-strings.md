```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> strs;
    while(n--) {
        string a;
        cin >> a;
        strs.emplace_back(a);
        sort(strs.begin(), strs.end());
        cout << find(strs.begin(), strs.end(), a) - strs.begin() << "\n";
    }
}
```

