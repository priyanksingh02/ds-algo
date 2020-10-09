```cpp

string Solution::countAndSay(int A) {
    if(A == 1)
        return "1";
    auto prev = countAndSay(A-1);
    int count = 1;
    int i = 1;
    string ans;
    for(; i < prev.size(); ++i) {
        if(prev[i-1] != prev[i]) {
            ans += to_string(count);
            ans.push_back(prev[i-1]);
            count = 1;
        }
        else {
            count++;
        }
    }
    ans += to_string(count);
    ans.push_back(prev[i-1]);
    return ans;
}
```
