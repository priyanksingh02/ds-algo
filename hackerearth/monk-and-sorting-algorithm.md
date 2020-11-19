```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    vector<pair<long,long>> v(n), store;
    for(auto &x: v) {
        long input;
        scanf("%ld",&input);
        x.first = x.second = input;
    }
    bool run = true;
    const long base = 1e5;
    vector<int> vals(n);
    while(run) {
        run = false;
        for(int i = 0; i < v.size(); ++i) {
            vals[i] = v[i].second % base;
            if(vals[i] > 0)
                run = true;
            v[i].second /= base;
        }
        if(!run)
            break;
        // map<int, vector<int>> m;
        vector<vector<int>> m(base);
        for(int i = 0; i < vals.size(); ++i) {
            m[vals[i]].push_back(i);
        }
        for(auto &x: m) {
            for(auto &y: x) {
                store.emplace_back(v[y]);
            }
        }
        v = move(store);
        for(auto &x: v) {
            printf("%ld ",x.first);
        }
        printf("\n");
    }
}
```

