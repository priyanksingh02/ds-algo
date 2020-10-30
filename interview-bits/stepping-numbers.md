```cpp
void search(int a, int b, long cur, set<int> & ans) {
    if(cur > b)
        return;
    if(a <= cur && cur <= b) {
        ans.insert(cur);
    }
    if(cur < 10)
        search(a,b, cur+1, ans);
    int rem = cur%10;
    if(rem > 0)
        search(a,b, cur*10+rem-1, ans);
    if(rem < 9)
        search(a,b, cur*10+rem+1, ans);
}

vector<int> Solution::stepnum(int A, int B) {
    set<int> ans;
    search(A, B, 0, ans);
    return {ans.begin(), ans.end()};
}
```
