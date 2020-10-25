## Generate all parenthesis I
```cpp
int Solution::isValid(string A) {
    stack<char> st;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == '(') {
            st.push(')');
        }
        else if(A[i] == '[') {
            st.push(']');
        }
        else if(A[i] == '{') {
            st.push('}');
        }
        else {
            if(st.empty() or A[i] != st.top())
                return false;
            st.pop();
        }
    }
    return st.empty();
}

```
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
