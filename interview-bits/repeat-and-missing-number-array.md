```cpp

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long sum = 0;
    long sqsum = 0;
    for(int i = 1; i <=n; ++i) {
        sum += i;
        sqsum += (long)i*i;
    }
    long csum = 0;
    long csqsum = 0;
    for(auto & x: A) {
        csum += x;
        csqsum += (long)x*x;
    }
    // u - unique, r - repeating
    long u_minus_r = sum - csum;
    long u_plus_r = (sqsum - csqsum)/u_minus_r;
    long u = (u_minus_r + u_plus_r)/2;
    long r = (u_plus_r - u);
    return {r,u};
}
```
