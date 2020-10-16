Greedy Solution
```cpp
int Solution::jump(vector<int> &A) {
    if(A.size() < 2)
        return 0;
    int can_reach = A[0];
    int will_reach = A[0];
    int steps = 1;
    for(int i = 0; i < A.size(); ++i) {
        can_reach = max(A[i] + i, can_reach);
        if(i == (int)A.size() - 1) {
            return steps;
        }
        if(i == will_reach) {
            if(will_reach == can_reach)
                return -1;
            ++steps;
            will_reach = can_reach;
        }
    }
    return -1;
}
```
DP solution: TLE
```cpp
int Solution::jump(vector<int> &A) {
    if(A.empty())
        return 1;
    vector<int> dp(A.size(), 0);
    dp.back() = 0;
    for(int i = int(A.size()) - 2; i >= 0; --i) {
        int dist = INT_MAX;
        for(int j = 1; j <= A[i] && i + j < A.size(); ++j) {
            dist  = min(dist, dp[i+j]);
        }
        if(dist == INT_MAX)
            dp[i] = INT_MAX;
        else
            dp[i] = 1 + dist;
    }
    return (dp[0] == INT_MAX)? -1: dp[0];
}
```
```cpp

int Solution::jump(vector<int> &A) {
    const int inf = 1e7;
    vector<int> dp(A.size(), inf);
    dp[0] = 0;
    for(int i= 0; i < A.size(); ++i) {
        if(dp[i] >= inf)
            return -1;
        for(int j = 1; j <= A[i] && i+j < A.size(); ++j) {
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    return dp.back();
}
```
