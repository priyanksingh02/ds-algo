```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

Runtime: O(n logn) ; We traverse a maximum of height of subsequence in worst case.

Idea: Try to create the sequence. The final sequence may not result in a correct answer but count will match the correct answer.
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    for(int i = 0;i < nums.size(); ++i) {
        int j = 0; 
        while(j < seq.size() and seq[j] < nums[i])
            j++;
        if(j == seq.size())
            seq.push_back(nums[i]);
        else
            seq[j] = nums[i];
    }
    return seq.size();
}
```
