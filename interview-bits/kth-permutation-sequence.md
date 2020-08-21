```cpp

string Solution::getPermutation(int n, int k) {
    k -= 1;
    vector<int> nums(n,0);
    for(int i = 0; i< n ;++i) {
        nums[i] = i + 1;
    }
    vector<int> ans;
    vector<int> mul(n, 1);
    for(int i = 2; i < n; i++) {
        if(mul[i-1]*i < mul[i-1])
            mul[i] = INT_MAX; // fix overflow
        else
            mul[i] = mul[i-1]*i;
    }
    for(int i = n - 1; i > 0; --i) {
        int pos = k/mul[i];
        assert(pos >= 0 && pos < nums.size());
        ans.push_back(nums[pos]);
        nums.erase(nums.begin() + pos);
        k %= mul[i];
    }
    assert(!nums.empty());
    ans.push_back(nums.front());
    string s;
    for(auto & x: ans) {
        s += to_string(x);
        // cout << x << " ";
    }
    return s;
}
```
