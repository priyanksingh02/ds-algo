```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; ++i) {
            string cur;
            if(i%3 == 0)
                cur += "Fizz";
            if(i%5 == 0)
                cur += "Buzz";
            if(cur.empty())
                cur = to_string(i);
            ans.push_back(cur);
        }
        return ans;
    }
};
```
