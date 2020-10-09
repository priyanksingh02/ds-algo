```cpp

vector<int> Solution::allFactors(int A) {
    vector<int> ans;
    int i = 1;
    for(; i * i < A; ++i) {
        if(A%i == 0) {
            ans.push_back(i);
            ans.push_back(A/i);
        }
    }
    if(i * i == A) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```
