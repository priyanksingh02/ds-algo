```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n= arr.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = i; j < n; ++j) {
                cur += arr[j];
                if((j-i+1)%2 != 0)
                    sum += cur;
            }
        }
        return sum;
    }
};
```
