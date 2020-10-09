```cpp
bool change = true;

bool check(const string & a, int low, int high) {
    if(low >= high) {
        return true;
    }
    if(a[low] == a[high]) {
        return check(a, low+1, high-1);
    }
    if(change) {
        change = false;
        return check(a, low+1, high) or check(a, low, high - 1);
    }
    return false;
}

int Solution::solve(string A) {
    change = true;
    return check(A, 0, (int)A.size()-1);
}
```
