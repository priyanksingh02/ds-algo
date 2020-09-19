```cpp

int Solution::solve(vector<vector<int> > &A) {
    vector<pair<int, bool>> t;
    for(int i = 0; i < A.size(); ++i) {
        t.push_back({A[i][0],true});
        t.push_back({A[i][1],false});
    }
    sort(t.begin(), t.end());
    int req = 0;
    int ans = 0;
    for(int i = 0; i < t.size(); ++i) {
        if(t[i].second) { // starting
            ++req;
        }
        else { // vacating
            --req;
        }
        ans = max(ans,req);
    }
    return ans;
}
```
