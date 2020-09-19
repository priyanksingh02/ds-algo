```cpp
// Finding max area given heights of rectangle
int area(vector<int> row) {
    sort(row.begin(), row.end(), greater<int>());
    int ans = 0;
    int height = INT_MAX;
    for(int i = 0; i < row.size(); ++i) {
        height = min(row[i], height);
        ans = max(ans, height*(i+1));
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int ans = 0;
    // convert to 1 D 
    for(int i = 0; i < m; ++i) {
        vector<int> row (n, 1);
        for(int j = i; j < m; ++j) {
            bool one = false;
            for(int k = 0; k < n; ++k) {
                if(row[k] && A[j][k]) {
                    if(i != j)
                        row[k]++; // calculate height
                    one = true;
                }
                else {
                    row[k] = 0;
                }
            }
            if(one) {
                ans = max(ans, area(row));
            }
            else 
                break;
        }
    }
    return ans;
}
```
