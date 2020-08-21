```cpp

int Solution::longestValidParentheses(string s) {
    int maxlen = 0;
    vector<int> longest(s.size(), 0);
    // for i = 6
    // ) ( ) ( ( ) ) (
    // 0 1 2 3 4 5 6 7
    // longest[i-1] means [4,5]
    // 6 matches with 3
    // and longest[2] is also added
    for(int i= 1; i < s.size(); ++i) {
        if(s[i] == ')' && i - longest[i-1] - 1 >= 0 && s[i-longest[i-1] - 1] == '(') {
            longest[i] = longest[i-1] + 2 + ((i - longest[i-1] - 2>= 0)? longest[i - longest[i-1] - 2]: 0);
            maxlen = max(maxlen, longest[i]);
        }
    }
    return maxlen;
}
```
