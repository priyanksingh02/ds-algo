```cpp

int atmost(const vector<int> &A, int k) {
    int i = 0, j = 0, ans = 0;
    unordered_map<int,int> m;
    while(j < A.size()) {
        m[A[j]]++;
        while(m.size() > k) {
            m[A[i]]--;
            if(m[A[i]] == 0)
                m.erase(A[i]);
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}
int Solution::solve(vector<int> &A, int B) {
    return atmost(A,B) - atmost(A, B-1);
}
```
