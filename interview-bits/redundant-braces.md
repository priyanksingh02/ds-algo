```cpp

bool isoperator(char c) {
    switch(c) {
        case '+': case '-': case '/': case '*': return true;
        default: return false;
    }
}

int Solution::braces(string A) {
    stack<bool> st;
    bool oper = false;
    for(int i =0; i < A.size(); ++i) {
        if(A[i] == '(') {
            st.push(oper);
            oper = false;
        }
        else if(A[i] == ')') {
            if(oper == false) {
                return true; // redundant
            }
            oper = st.top();
            st.pop();
        }
        else if(isoperator(A[i])) {
            oper = true;
        }
    }
    return false;
}
```
