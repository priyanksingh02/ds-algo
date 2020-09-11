```cpp
string Solution::solve(string A) {
    int win = false;
    for(int i = 1; i < A.size(); ++i) {
        if(A[i] != A[i-1]) {
            win = true;
            break;
        }
    }
    if(win)
        return "Alice";
    else
        return "Bob";
}
```
