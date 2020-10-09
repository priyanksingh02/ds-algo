```cpp

int Solution::romanToInt(string A) {
    unordered_map<char, int> val {
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},  
      {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        int t = val[A[i]];
        if(i + 1 < A.size() && val[A[i]] < val[A[i+1]])
            t = -t;
        ans += t;
    }
    return ans;
}
```
