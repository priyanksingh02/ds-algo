```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    int k;
    cin >> a >> k;
    vector<string> s;
    for(int i = 0; i < a.size(); ++i) {
        s.push_back(a.substr(i));
    }
    sort(s.begin(), s.end());
    cout << s[k-1];
}
```

