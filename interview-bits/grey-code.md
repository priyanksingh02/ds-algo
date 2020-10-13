```cpp
int grey(int a) {
    int ans = 0;
    bool bit = 0;
    for(int i = 30; i >= 0; --i) {
        if((bool)(a & (1 << i)) ^ (bool)(a & (1 << (i+1)))) {
            ans |= (1 << i);
        }
    }
    return ans;
}
vector<int> Solution::grayCode(int A) {
    int lim = 1<<A;
    vector<int> ans;
    for(int i= 0; i < lim; ++i) {
        ans.push_back(grey(i));
    }
    return ans;
}
```
