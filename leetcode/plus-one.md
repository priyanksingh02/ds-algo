```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        int i = 0;
        vector<int> ans;
        while(carry or i < digits.size()) {
            int sum = carry;
            if(i < digits.size())
                sum += digits[i++];
            ans.push_back(sum%10);
            carry = sum/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
