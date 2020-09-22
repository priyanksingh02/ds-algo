```cpp
class Solution {
    vector<string> ans;
public:
    void gen(int open, int close, string & cur, int n) {
        if(open == close && open == n) {
            ans.push_back(cur);
            return;
        }
        if(open < n) {
            cur.push_back('(');
            gen(open+1, close,cur, n);
            cur.pop_back();
        }
        if(close < open) {
            cur.push_back(')');
            gen(open, close+1, cur, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        string cur;
        gen(0, 0, cur, n);
        return ans;
    }
};
```
