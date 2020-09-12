```cpp
int Solution::colorful(int A) {
    vector<int> digits;
    while(A) {
        digits.push_back(A%10);
        A/= 10;
    }
    unordered_set<int> seen;
    for(int i = 0; i < digits.size(); ++i) {
        int cur = 1;
        for(int j = i; j < digits.size(); ++j) {
            cur *= digits[j];
            if(!seen.insert(cur).second)
                return false;
        }
    }
    return true;
}
```
