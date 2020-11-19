```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> S(n);
        for(auto &x: S)
            cin >> x;
        sort(S.begin(), S.end());
        bool found = false;
        for(int i = 0; i < S.front().size() && i < S.back().size(); ++i) {
            if(S.front()[i] != S.back()[i]) {
                if(i == 0)
                    cout << "-1\n";
                else 
                    cout << S.front().substr(0, i) << "\n";
                found = true;
                break;
            }
        }
        if(!found)
            cout << S.front() << "\n";
    }
}
```

