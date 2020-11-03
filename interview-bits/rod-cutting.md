# Rod Cutting
Memory Limit Exceeded - Go for Bottom up approach!
Logic is correct!
```cpp
int cut(vector<int> & points, int low, int high, int N,
        vector<vector<int>> & pos, vector<vector<int>> & dp) {
    if(low > high)
        return 0;
    if(dp[low][high] != -1)
        return dp[low][high];
    int cost = 1e9; //minimize this
    for(int i = low; i <= high; ++i) {
        int l = cut(points, low, i-1, N, pos, dp);
        int r = cut(points, i+1, high, N, pos, dp);
        if(cost > l+r) {
            cost = l+r;
            pos[low][high] = i;
        }
    }
    int a = ((low - 1 < 0)?0:points[low-1]);
    int b = ((high+1 >= points.size())?N:points[high+1]);
    int cur_cost = b - a;
    dp[low][high] = cost + cur_cost;
    return dp[low][high];
}

vector<int> ans;
void travel(int low, int high, vector<int> & points,
        vector<vector<int>> & pos) {
    if(low > high)
        return;
    int cut_pos = pos[low][high];
    ans.push_back(points[cut_pos]);
    travel(low, cut_pos - 1, points, pos);
    travel(cut_pos+1, high, points, pos);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    int n = B.size();
    vector<vector<int>> pos (n, vector<int> (n, 0));
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cut(B, 0, n-1, A, pos, dp);
    ans.clear();
    travel(0, n-1, B, pos);
    return ans;
}
```

