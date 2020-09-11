```cpp
int Solution::singleNumber(const vector<int> &A) {
    int x = 0;
    for(int i =0; i < A.size(); ++i) {
        x ^= A[i];
    }
    return x;
}
```

## Single Number II

count number of zeros and ones. one of these will be divisible by 3. The ones which are
not divisible by 3 are actually the part of the ans;
```cpp
int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
        int zero = 0;
        for(int j = 0; j < A.size(); ++j) {
            if((A[j] & (1 << i)) == 0)
                ++zero;
        }
        // cout << zero << endl;
        if(zero % 3 == 0)
            ans |= (1 << i);
    }
    return ans;
}
```
