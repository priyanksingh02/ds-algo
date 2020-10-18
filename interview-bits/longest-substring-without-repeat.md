```cpp

int Solution::lengthOfLongestSubstring(string A) {
    vector<int> cnt(256, 0);
    int i = 0, j= 0;
    int maxlen = 0;
    while(i < A.size()) {
        cnt[A[i]]++;
        while(j < i && cnt[A[i]] > 1) {
            cnt[A[j]]--;
            j++;
        }
        maxlen = max(maxlen, i-j+1);
        i++;
    }
    return maxlen;
}
```
