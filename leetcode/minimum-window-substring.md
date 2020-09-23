```cpp
class Solution {
public:
    bool cover(const vector<int> & count) {
        for(int i = 0; i < count.size(); ++i) {
            if(count[i] > 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> count(255, 0);
        for(auto & x: t)
            count[x]++;
        int slow = 0, fast = 0;
        int ans = 1e9, pos = -1;
        while(fast < s.size()) {
            count[s[fast]]--;
            while(slow <= fast && cover(count)) {
                if(fast-slow+1 < ans) {
                    ans = fast-slow + 1;
                    pos = slow;
                }
                count[s[slow]]++;
                slow++;
            }
            fast++;
        }
        if(pos == -1)
            return "";
        return s.substr(pos, ans);
    }
};
```
