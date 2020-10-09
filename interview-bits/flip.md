Based on Kadane's Algorithm
```cpp

vector<int> Solution::flip(string A) {
    int start = -1, end = -1, x = -1, y = -1, len = 0, maxlen = 0;
    for(int i= 0; i < A.size(); ++i) {
        if(A[i] == '0') {
            len++;
            if(start == -1)
                start = i;
            end = i;
        } else {
            len--;
            if(len < 0) {
                start = -1;
                end = -1;
                len= 0;
            }
        }
        if(maxlen < len) {
            maxlen = len;
            x = start;
            y = end;
        }
    }
    if(maxlen > 0)
        return {x + 1, y + 1};
    else
        return {};
}
```
