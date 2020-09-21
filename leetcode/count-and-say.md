```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        int count = 1;
        string ans;
        string prev = countAndSay(n-1);
        for(int i = 0; i < prev.size(); ++i) {
            if(i + 1 < prev.size() && prev[i] == prev[i+1]) {
                ++count;
            }
            else {
                ans += to_string(count);
                ans.push_back(prev[i]);
                count = 1;
            }
        }
        // cout << n << " " << ans << endl;
        return ans;
    }
};
```
