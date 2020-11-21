```cpp
bool ispar(string str) {
    stack<char> st;
    for(int i= 0; i < (int)str.size(); ++i) {
        if(str[i] == '{') {
            st.push('}');
        }
        else if(str[i] == '[')
            st.push(']');
        else if(str[i] == '(')
            st.push(')');
        else {
            if(st.empty() or st.top() != str[i])
                return false;
            st.pop();
        }
    }
    return st.empty();
}
```

