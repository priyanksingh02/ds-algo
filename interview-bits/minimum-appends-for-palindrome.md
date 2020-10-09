```cpp

int Solution::solve(string A) {
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == A.back()) {
            int j = i + 1;
            int k = (int)A.size() - 2;
            while(j < k && A[j] == A[k]) {
                j++;
                k--;
            }
            if(j >= k) {
                ans = i;
                break;
            }
        }
    }
    return ans;
}
```
