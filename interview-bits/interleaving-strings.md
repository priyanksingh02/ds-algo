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
