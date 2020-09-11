```cpp
int Solution::lengthOfLastWord(const string A) {
    stringstream ss {A};
    string word;
    int ans = 0;
    while(ss >> word) {
        ans = word.size();
    }
    return ans;
}
```
