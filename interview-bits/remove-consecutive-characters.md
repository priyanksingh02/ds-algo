```cpp

string Solution::solve(string A, int B) {
    int count = 0;
    string ans;
    for(int i = 0; i< A.size(); ++i) {
        if(i + 1 < A.size() && A[i] == A[i+1]) {
            ++count;
        }
        else {
            if(count + 1 != B) {
                ans += string(count + 1, A[i]);
            }
            count = 0;
        }
    }
    return ans;
}
```
