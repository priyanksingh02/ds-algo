```cpp
class Solution {
    vector<int> org;
public:
    Solution(vector<int>& nums) {
        org = nums;
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = org.size();
        --n;
        vector<int> ans = org;
        while(n > 0) {
            int pos = rand()%(n+1);
            swap(ans[pos], ans[n]);
            --n;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 ```
