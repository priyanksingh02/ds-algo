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
