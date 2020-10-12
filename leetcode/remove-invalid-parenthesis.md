```cpp
class Solution {
    set<string> ans;
public:
    void build(const string & s, int i , int l, int r, int left, int right, string & cur) {
        if(i == s.size()) {
            if(left == 0 && right == 0 && l == r) {
                ans.insert(cur);
            }
            return ;
        }
        if(s[i] == '(') {
            if(left) {
                build(s, i+1, l, r, left-1, right, cur);
            }
            cur.push_back('(');
            build(s, i+1, l+1, r, left, right, cur);
            cur.pop_back();
        }
        else if(s[i] == ')') {
            if(right) {
                build(s, i+1, l, r, left, right -1 , cur);
            }
            if(l > r) {
                cur.push_back(')');
                build(s, i+1, l, r+1, left, right, cur);
                cur.pop_back();
            }
        }
        else {
            cur.push_back(s[i]);
            build(s,i+1, l, r, left, right, cur);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++left;
            }
            else if(s[i] == ')') {
                if(left > 0)
                    --left;
                else
                    ++right;
            }
        }
        string cur;
        build(s, 0, 0, 0, left, right, cur);
        return {ans.begin(), ans.end()};
    }
};
```
```cpp
class Solution {
    set<string> ans;
public:
    bool valid(const string& s) {
        int level = 0;
        for(int i =0; i < s.size(); ++i) {
            if(s[i] == '(')
                ++level;
            else if(s[i] == ')' && --level < 0) {
                return false;
            }
        }
        return level == 0;
    }
    void build(const string& s, int i, int left, int right, string & cur) {
        if(i == s.size()) {
            if(left == 0 && right == 0 && valid(cur)) {
                ans.insert(cur);
            }
            return;
        }
        if(s[i] == '(') {
            if(left)
                build(s, i+1, left - 1, right, cur);
            cur.push_back('(');
            build(s, i+1, left, right, cur);
            cur.pop_back();
        }
        else if(s[i] == ')') {
            if(right)
                build(s, i+1, left, right-1, cur);
            cur.push_back(')');
            build(s, i+1, left, right, cur);
            cur.pop_back();
        }
        else {
            cur.push_back(s[i]);
            build(s, i+1, left, right, cur);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++left;
            }
            else if(s[i] == ')') {
                if(left > 0)
                    --left;
                else
                    ++right;
            }
        }
        string cur;
        build(s, 0, left, right, cur);
        return {ans.begin(), ans.end()};
    }
};
```
