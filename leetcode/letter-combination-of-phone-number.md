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

```cpp
class Solution {
    map<char, string> keys = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void gen(vector<string> & ans, string & cur, int pos, string & digits) {
        if(pos == digits.size()) {
            if(!cur.empty()) ans.push_back(cur);
            return;
        }
        char choice = digits[pos];
        for(int i = 0; i < keys[choice].size(); ++i) {
            cur.push_back(keys[choice][i]);
            gen(ans, cur, pos+1, digits);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        gen(ans, cur, 0, digits);
        return ans;
    }
};

```
