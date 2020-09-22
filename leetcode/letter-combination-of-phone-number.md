```cpp
class Solution {
    unordered_map<int, string> m = {
        {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
        {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };
public:
    void gen(string & digit, int pos, string& cur, vector<string> & ans) {
        if(pos == digit.size()) {
            ans.push_back(cur);
            return ;
        }
        string & str = m[digit[pos] - '0'];
        for(auto & c: str) {
            cur.push_back(c);
            gen(digit, pos+1, cur, ans);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        string cur;
        vector<string> ans;
        gen(digits, 0, cur, ans);
        return ans;
    }
};
```
