# Find the longest path in a matrix with given constraints
Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4
The longest path is 6-7-8-9.
*Path should have consecutive increasing elements.*
Movement in 4-direction allowed.
```cpp
vector<vector<int>> dp;
vector<pair<int,int>> direction {{0,1},{1,0},{-1,0},{0,-1}};

int dfs(int i, int j, int req_elem, vector<vector<int>> & matrix) {
   if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or matrix[i][j] != req_elem)
       return 0;
   if(dp[i][j] != 0) {
        return dp[i][j];
   }
   dp[i][j] = 0;
   for(auto &d : direction) {
       dp[i][j] = max(dp[i][j], dfs(i+d.first, j+d.second, matrix[i][j] + 1, matrix) + 1);
   }
   return dp[i][j];
}

int longest_path(vector<vector<int>> & matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    dp.clear();
    dp.resize(m, vector<int> (n, 0));
    int maxlen = 0; 
    for(int i= 0; i< m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!dp[i][j])
                dfs(i, j, matrix[i][j], matrix);
            maxlen = max(maxlen, dp[i][j]);
        }
    }
    return maxlen; 
}
```
