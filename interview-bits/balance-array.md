```cpp

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> odd_bf, odd_af, even_bf, even_af;
    int prev_even = 0, prev_odd = 0;
    for(int i = 0; i < n; ++i) {
        even_bf.push_back(prev_even);
        odd_bf.push_back(prev_odd);
        if(i%2 == 0) {
            prev_even += A[i];
        }
        else {
            prev_odd += A[i];
        }
    }
    prev_even = 0, prev_odd = 0;
    for(int i = n-1; i >= 0; --i) {
        even_af.push_back(prev_even);
        odd_af.push_back(prev_odd);
        if(i%2 == 0)
            prev_even += A[i];
        else
            prev_odd += A[i];
    }
    reverse(even_af.begin(), even_af.end());
    reverse(odd_af.begin(), odd_af.end());
 
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(even_bf[i] + odd_af[i] == even_af[i] + odd_bf[i])
            ++ans;
    }
    return ans;
}
```
