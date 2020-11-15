```cpp
int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, bool>> times;
    for(int i = 0;i < n; ++i) {
        times.push_back({arr[i], false});
        times.push_back({dep[i], true});
    }
    sort(times.begin(), times.end());
    int req = 0, ans = 0;
    for(int i = 0; i < times.size(); ++i) {
        if(times[i].second) {
            // departure
            --req;
        }
        else { // arrive
            ++req;
        }
        ans = max(ans, req);
    }
    return ans;
}

```

