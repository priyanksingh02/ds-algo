```cpp
bool is_sym(const string & s) {
    return s == "+" or s == "-" or s == "/" or s == "*";
}

int eval(const string & s, int a, int b) {
    if(s == "+")
        return a+b;
    else if(s == "*")
        return a*b;
    else if(s == "/")
        return a/b;
    else
        return a-b;
}

int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i = 0; i < A.size(); ++i) {
        if(is_sym(A[i])) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(eval(A[i], a, b));
        }
        else {
            st.push(stoi(A[i]));
        }
    }
    return st.top();
}
```
