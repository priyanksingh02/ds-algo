```cpp
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, [](struct val & a, struct val & b) {
        return a.first < b.first or (a.first == b.first && a.second < b.second);
    });
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(p[i].first > p[j].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp.back();
}
```

