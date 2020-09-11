```cpp
string Solution::convert(string A, int B) {
    vector<string> grid(B);
    if(B < 2)
        return A;
    int pos = 0;
    int dir = 1;
    for(int i = 0; i < A.size(); ++i) {
        grid[pos].push_back(A[i]);
        if(dir) {
            pos++;
            if(pos == B) {
                dir = 0;
                pos = B-2;
            }
        }
        else {
            pos--;
            if(pos == -1) {
                pos = 1;
                dir = 1;
            }
        }
    }
    string ans;
    for(auto & s: grid) {
        ans+= s;
    }
    return ans;
}
```
