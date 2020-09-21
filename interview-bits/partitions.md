```cpp
int Solution::solve(int a, vector<int>& b) {
    int sum = 0;
    for(auto & x: b)
        sum += x;
    if(sum%3)
        return 0;
    int s = 0, c1 = 0;
    sum/= 3;
    int ans = 0;
    for(int i = 0; i < a-1; ++i) {
        s += b[i];
        if(s == 2*sum and i > 0)
            ans += c1;
        if(s == sum)
            c1++;
    }
    return ans;
}
```

```cpp

int Solution::solve(int a, vector<int>& b) {
    int sum = 0;
    for(auto & x: b)
        sum+=x;
    if(sum%3)
        return 0;
    if(sum == 0) {
        int c = 0;
        int s = 0;
        for(int i = 0; i < a - 1; ++i) {
            s += b[i];
            if(s == 0)
                ++c;
        }
        return c*(c-1)/2;
    }
    vector<int> suf(a+1, 0);
    sum/=3;
    int s = 0;
    for(int i = 0; i < a; ++i) {
        s += b[i];
        if(s == 2*sum)
            suf[i] = 1;
    }
    for(int i = (int)suf.size() - 2; i >= 0; --i) {
        suf[i] += suf[i+1];
    }
    s = 0;
    int ans = 0;
    for(int i = 0; i < a-1; ++i) {
        s += b[i];
        if(s == sum)
            ans += suf[i];
    }
    return ans;
}
```
