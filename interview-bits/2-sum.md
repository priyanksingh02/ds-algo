```cpp

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> m;
    for(int i = 0; i < A.size(); ++i) {
        if(m.count(B-A[i])) {
            return {m[B-A[i]], i+1};
        }
        if(!m.count(A[i]))
            m[A[i]] = i+1;
    }
    return {};
}
```
