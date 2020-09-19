Idea: 
dp[i] denotes ans array size for capacity i
if a kick is used whose power is p:
    then dp[current capacity] - dp[cur power] == 1
    
Assume this approach as finding the selected elements of knapsack
```cpp
vector<int> Solution::solve(int A, vector<int> &B) {
    vector<int> dp(A+1, 0);
    int min_elem = *min_element(B.begin(), B.end());
    for(int i = 0; i <= A; ++i) {
        dp[i] = i/min_elem;
    }
    int i = 0;
    vector<int> ans;
    while(A > 0 && i < B.size()) {
        if(A-B[i] >= 0 && dp[A] - dp[A-B[i]] == 1) {
            ans.push_back(i);
            A -= B[i];
        }
        else {
            i++;
        }
    }
    return ans;
}
```

```cpp
vector<int> Solution::solve(int A, vector<int> &B) {
    int kicks = *min_element(B.begin(), B.end());
    vector<int> dp(A+1);
    for(int i = 0; i < dp.size(); ++i) {
        dp[i] = i/kicks;
    }
    int max_till_now = B[0];
    vector<int> ans; 
    int w = A;
    int i = 0;
    while(w > 0 && i < B.size()) {
        if(w - B[i] >= 0 && dp[w] - dp[w-B[i]] == 1) {
            ans.push_back(i);
            w -= B[i];
        }
        else {
            i++;
            while(i < B.size() && B[i] >= max_till_now)
                i++;
            if(i < B.size()) {
                max_till_now = B[i];
            }
        }
    }
    return ans;
}
```
