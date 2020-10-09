```cpp

string Solution::longestPalindrome(string A) {
    int n = A.size();
    int ansi = 0, ansj = 0, maxlen = 0;
    vector<vector<bool>> pal(n, vector<bool> (n, false));
    for(int i = n-1; i >= 0; --i) {
        for(int j = i; j < n; ++j) {
            if(i == j) {
                pal[i][j] = true;
            }
            else if(A[i] == A[j]) {
                if(i+1 > j-1)
                    pal[i][j] = true;
                else
                    pal[i][j] = pal[i+1][j-1];
            }
            else 
                pal[i][j] = false;
            
            if(pal[i][j] && maxlen <= j - i + 1) {
                maxlen = j - i + 1;
                ansi = i;
                ansj = j;
            }
        }
    }
    return A.substr(ansi, ansj- ansi + 1);
}
```
