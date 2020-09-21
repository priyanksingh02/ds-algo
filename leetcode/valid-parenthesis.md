```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        bool done = false;
        for(int i = 0; i< s.size() && !done; ++i) {
            switch(s[i]) {
                case '{': open.push('}'); break;
                case '[': open.push(']'); break;
                case '(': open.push(')'); break;
                case ']': case ')': case '}':
                    if(open.empty() or open.top() != s[i])
                        done = true;
                    else 
                        open.pop();
            }
        }
        return !done && open.empty();
    }
};
```
