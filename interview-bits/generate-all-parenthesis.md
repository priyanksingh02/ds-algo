## Generate all parenthesis II
```cpp
vector<string> ans;
void gen(int left, int right, int n, string & cur) {
    if(left == right && left == n) {
        ans.push_back(cur);
        return;
    }
    if(left < n) {
        cur.push_back('(');
        gen(left+1, right, n, cur);
        cur.pop_back();
    }
    if(left > right) {
        cur.push_back(')');
        gen(left, right+1, n, cur);
        cur.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n) {
    ans.clear();
    string cur;
    gen(0, 0, n, cur);
    return ans;
}
```
