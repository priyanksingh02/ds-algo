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
```cpp

int Solution::longestConsecutive(const vector<int> &A) {
    set<int> st;
    for(int x: A)
        st.insert(x);
    int maxlen = 0;
    for(int x: st) {
        if(st.count(x-1))
            continue;
        int len = 1;
        int t = x+1;
        while(st.count(t)) {
            len++;
            t += 1;
        }
        maxlen = max(maxlen, len);
    }
    return maxlen;
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
