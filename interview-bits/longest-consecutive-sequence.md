O(n)
```cpp

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> nums;
    for(auto & x: A) {
        nums.insert(x);
    }
    int ans = 0;
    for(auto & x: nums) {
        if(nums.count(x - 1) == 0) {
            int streak = 1;
            int elem = x;
            while(nums.count(elem + 1)) {
                ++streak;
                ++elem;
            }
            ans = max(ans, streak);
        }
    }
    return ans;
}

```
O(nlogn)
```cpp

int Solution::longestConsecutive(const vector<int> &A) {
    if(A.empty())
        return 0;
    set<int> seen;
    for(auto & x: A) {
        seen.insert(x);
    }
    int ans = 0;
    int cur = 1;
    for(auto & x: seen) {
        if(seen.count(x+1)) {
            cur  += 1;
        }
        else {
            ans = max(cur, ans);
            cur = 1;
        }
    }
    return ans;
}
```
