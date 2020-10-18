x/n = 1st number
x%n = 2nd number

choose: ans*n + org

(ans*n + org)%n = org
(ans*n + org)/n = ans
```cpp
void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        int org = A[i]%n;
        A[i] += (A[org]%n)*n;
    }
    for(int i = 0; i < n; ++i) {
        A[i] /= n;
    }
}
```
