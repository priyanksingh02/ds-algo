```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> rep;
        stack<string> st;
        rep.push(0);
        st.push("");
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                rep.top() = rep.top()*10 + (s[i]-'0');
            }
            else if(s[i] == '[') {
                rep.push(0);
                st.push("");
            }
            else if(s[i] == ']') {
                rep.pop();
                string tmp = st.top();
                st.pop();
                string append;
                while(rep.top()--) {
                    append+= tmp;
                }
                st.top() += append;
                rep.top() = 0;
            }
            else {
                st.top().push_back(s[i]);
            }
        }
        return st.top();
    }
};
```

