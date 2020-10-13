## Palindrome Partitioning
```cpp
vector<vector<bool>> pal;
vector<vector<string>> ans;

void gen(string & A, int pos, vector<string> & cur) {
    if(pos == A.size()) {
        ans.push_back(cur);
        return;
    }
    for(int i = pos; i < A.size(); ++i) {
        if(pal[pos][i]) {
            cur.push_back(A.substr(pos, i-pos+1));
            gen(A, i+1, cur);
            cur.pop_back();
        }
    }
}


vector<vector<string> > Solution::partition(string A) {
    pal.clear();
    int n = A.size();
    pal.resize(n, vector<bool> (n, false));
    for(int i = n-1; i >= 0; --i) {
        for(int j = i; j < n; ++j) {
            if(i==j) {
                pal[i][j] = true;
            }
            else if(A[i] == A[j]) {
                if(i+1 == j) {
                    pal[i][j] = true;
                }
                else {
                    pal[i][j] = pal[i+1][j-1];
                }
            }
        }
    }
    ans.clear();
    vector<string> cur;
    gen(A, 0, cur);
    return ans;
}

```
## Palindrome Partitioning II
```cpp
vector<vector<int>> dp;
vector<vector<int>> cut;

bool pal(const string & s, int i, int j) {
    if(i > j)
        return true;
    if(i==j) {
       return dp[i][j] = true;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j])
        return dp[i][j] = pal(s, i+1, j-1);
    return dp[i][j] = false;
}

int solve(const string &s , int i, int j) {
    if(i > j) {
        return 0;
    }
    if(cut[i][j] != -1) {
        return cut[i][j];
    }
    if(dp[i][j] == 1) {
         return cut[i][j] = 0;
    }
    cut[i][j] = INT_MAX;
    for(int k = i; k < j; ++k) {
        cut[i][j] = min(cut[i][j], 1 + solve(s,i,k) + solve(s,k+1,j));
    }
    assert(cut[i][j] != INT_MAX);
    return cut[i][j];
}

int Solution::minCut(string A) {
    dp.clear();
    cut.clear();
    dp.resize(A.size(), vector<int>(A.size(), -1));
    for(int i = 0; i < A.size(); ++i) {
        for(int j = i; j < A.size(); ++j) {
            pal(A,i,j);       
        }
    }
    cut.resize(A.size(), vector<int>(A.size(), -1));
    int ans = solve(A, 0, (int)A.size() -1);
    return ans;
}
```
