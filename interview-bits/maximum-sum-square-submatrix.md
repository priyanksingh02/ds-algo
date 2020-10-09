```cpp

int process(vector<int> & arr, int B) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < B; ++i) {
        sum += arr[i];
    }
    int maxsum = sum;
    for(int i = B; i < n; ++i) {
        sum -= arr[i-B];
        sum += arr[i];
        maxsum = max(maxsum , sum);
    }
    return maxsum;
}

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < B; ++j) {
            arr[i] += A[j][i];
        }
    }
    int ans = process(arr, B);
    for(int j = B; j < n; ++j) {
        for(int i  = 0; i < n; ++i) {
            arr[i] -= A[j-B][i];
            arr[i] += A[j][i];
        }
        ans = max(ans, process(arr, B));
    }
    return ans;
}
``
