```cpp

int Solution::solve(vector<int> &A, int B) {
    int i = 0, j = 0;
    int ans = 0;
    while(i < A.size()) {
        int sum = 0;
        int j = i;
        while(j < A.size()) {
            sum += A[j];
            if(sum < B) {
                ++ans;
            }
            else
                break;
            j++;
        }
        i++;
    }
    return ans;
}
```
