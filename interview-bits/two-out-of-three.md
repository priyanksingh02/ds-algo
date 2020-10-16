```cpp

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int, int> cnt;
    for(int i =0; i < A.size(); ++i) {
        cnt[A[i]] = 1;
    }
    for(int j = 0; j < B.size(); ++j) {
        if(cnt.count(B[j])) {
            if(cnt[B[j]] == 1)
                cnt[B[j]] = 3;
        }
        else 
            cnt[B[j]] = 2;
    }
    for(int i = 0; i < C.size(); ++i) {
        if(cnt.count(C[i]))
            cnt[C[i]] = 3;
    }
    vector<int> ans;
    for(auto x: cnt) {
        if(x.second == 3)
            ans.push_back(x.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```
