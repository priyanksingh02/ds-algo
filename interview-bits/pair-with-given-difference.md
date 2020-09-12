```cpp
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> ht;
    for(auto & x: A)
        ht[x]++;
    for(auto & x: A) {
        if(x == x + B) {
            if(ht[x] > 1)
                return true;
        }
        else if(ht[x+B] >= 1)
            return true;
    }
    return false;
}
```
