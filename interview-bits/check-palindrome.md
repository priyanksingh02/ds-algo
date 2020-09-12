```cpp
int Solution::solve(string A) {
    vector<int> count(26, 0);
    for(auto & c: A)
        count[c-'a']++;
    int odd = 0;
    for(int i = 0; i < count.size(); ++i) {
        if((count[i] & 1) && ++odd > 1)
            return false;
    }
    return true;
}
```
