```cpp
string Solution::minWindow(string A, string B) {
    vector<int> count (155, 0);
    for(auto & c: B) {
        count[c]++;
    }
    int l = 0, r = 0;
    int idx = -1, minlen = A.size() + 1;
    int rem = B.size(); // remaining
    while(r < A.size()) {
        if(--count[A[r]] >= 0)
            rem--;
        while(rem == 0) {
            if(minlen > r - l + 1) {
                minlen = r - l + 1;
                idx = l;    
            }
            if(++count[A[l]] > 0)
                rem++;
            l++;
        }
        r++;
    }
    if(idx == -1) return "";
    return A.substr(idx, minlen);
}
```
```cpp
bool check(const vector<int> & count) {
    for(auto & x: count) {
        if(x > 0)
            return false;
    }
    return true;
}

string Solution::minWindow(string A, string B) {
    vector<int> count (155, 0);
    for(auto & c: B) {
        count[c]++;
    }
    int l = 0, r = 0;
    int idx = -1, minlen = A.size() + 1;
    while(r < A.size()) {
        count[A[r]]--;
        if(check(count)) {
            while(l <= r && check(count)) {
                if(minlen > r - l + 1) {
                    minlen = r - l + 1;
                    idx = l;    
                }
                count[A[l]]++;
                l++;
            }
        }
        r++;
    }
    if(idx == -1) return "";
    return A.substr(idx, minlen);
}
```
