```cpp

int dp[160][160][160];

bool find(const string & A, int i, const string & B, int j,
    const string & C, int k) {
        if(i == A.size() && j == B.size() && k == C.size())
            return 1;
        if(i == A.size() && C.substr(k) == B.substr(j))
            return 1;
        if(j == B.size() && C.substr(k) == A.substr(i))
            return 1;
        if(i == A.size() or j == B.size() or k == C.size())
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        if(A[i] == C[k] && B[j] == C[k]) {
            return dp[i][j][k] = find(A, i+1, B, j, C, k+1) || find(A, i, B, j+1, C, k+1); 
        }
        else if(A[i] == C[k]) {
            return dp[i][j][k] = find(A, i+1, B, j, C, k+1);
        }
        else if(B[j] == C[k]) {
            return dp[i][j][k] = find(A, i, B, j+1, C, k+1);
        }
        else
            return dp[i][j][k] = 0;
    }

int Solution::isInterleave(string A, string B, string C) {
    if(A.size() + B.size() != C.size())
        return false;
    memset(dp, -1, sizeof(dp));
    return find(A, 0, B, 0, C, 0);
}
```

```cpp

bool solve(string & a, int i, string & b, int j, string &  c, int k) {
    if(i < 0) {
        return b.substr(0,j+1) == c.substr(0, k+1);
    }
    if(j < 0) {
        return a.substr(0,i+1) == c.substr(0, k+1);
    }
    if(a[i] == c[k] && b[j] == c[k]) {
        return solve(a,i-1,b,j,c,k-1) || solve(a,i,b,j-1,c,k-1);
    }
    else if(a[i] == c[k]) {
        return solve(a,i-1,b,j,c,k-1);
    }
    else if(b[j] == c[k]){
        return solve(a,i,b,j-1,c,k-1);
    }
    else {
        return false;
    }
}

int Solution::isInterleave(string A, string B, string C) {
    if(A.size() + B.size() != C.size())
        return false;
    
    return solve(A,(int)A.size() -1 ,
        B, (int)B.size() - 1,
        C, (int)C.size() - 1);
    
}
```

