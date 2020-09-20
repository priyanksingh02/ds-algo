```cpp
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> freq (n+1, 0);
        for(auto & v: requests) {
            freq[v[0]]++;
            freq[v[1]+1]--;
        }
        for(int i = 1; i < freq.size(); ++i) {
            freq[i] += freq[i-1];
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        const int mod = 1e9 + 7;
        for(int i = 0; i < n; ++i) {
            ans += ((long long)freq[i]*nums[i])%mod;
            ans %= mod;
        }
        return ans;
    }
};
```
