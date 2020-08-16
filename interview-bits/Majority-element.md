Time: O(nlogn) 
Space: O(1)
```cpp

int Solution::majorityElement(const vector<int> &A) {
    vector<int> b {A};
    sort(b.begin(), b.end());
    return b[b.size()/2];
}

```

Time: O(n)
Space: O(1)
Idea: If two num are not same, removing both won't change majority element
```cpp

class Solution {
    public:
        int majorityElement(vector<int> &num) {
            int majorityIndex = 0;
            for (int count = 1, i = 1; i < num.size(); i++) {
                num[majorityIndex] == num[i] ? count++ : count--;
                if (count == 0) {
                    majorityIndex = i;
                    count = 1;
                }
            }

            return num[majorityIndex];
        }
};

``` 
