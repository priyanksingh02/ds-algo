```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        vector<int> left;
        vector<int> right;
        for(int i = 0; i< arr.size(); ++i) {
            if(left.empty() || arr[i-1] <= arr[i])
                left.push_back(arr[i]);
            else
                break;
        }
        for(int i = (int)arr.size() - 1; i >= 0; --i) {
            if(right.empty() || arr[i] <= arr[i+1])
                right.push_back(arr[i]);
            else
                break;
        }
        reverse(right.begin(), right.end());
        // merge left and right to get non-decreasing array of maximum length
        int ans = max(left.size(), right.size());
        for(int i = 0; i < left.size(); ++i) {
            int pos = lower_bound(right.begin(), right.end(), left[i]) - right.begin();
            ans = max(ans, i+1+(int)right.size() - pos);
        }
        return max(0,(int)arr.size() - ans); // overlap in left && right can cause ans to be greater than arr.size()
                // example : 1 2 3 4 5 : left = 1 2 3 4 5 right = 1 2 3 4 5 : ans = 1 1 2 3 4 5 (one of the best merge)
    }
};
```
