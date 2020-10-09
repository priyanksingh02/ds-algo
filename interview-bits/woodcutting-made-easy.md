```cpp

long cut(vector<int> & A, int height) {
    long count = 0;
    for(int i = 0; i < A.size(); ++i) {
        count += max(0, A[i] - height);
    }
    return count;
}

int Solution::solve(vector<int> &A, int B) {
    int low = 0;
    int high = *max_element(A.begin(),A.end());
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(cut(A, mid) >= B) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}
```
