```cpp
int Solution::solve(vector<int>&a, int b) {
    int n = a.size();
    int sum = 0;
    for(auto & x: a)
        sum += x;
    if( b >= n)
        return sum;
    int cur_sum = 0;
    int req = n - b;
    for(int i = 0; i < req; ++i) {
        cur_sum += a[i];
    }
    int min_sum = cur_sum;
    for(int i = req; i < n; ++i) {
        cur_sum += a[i];
        cur_sum -= a[i-req];
        min_sum = min(min_sum, cur_sum);
    }
    return sum - min_sum;
}
```
