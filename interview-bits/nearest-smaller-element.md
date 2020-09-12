```cpp
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    st.push(-1);
    int n = A.size();
    vector<int> ans (n, 0);
    for(int i = 0; i < n; ++i) {
        while(st.top() >= A[i])
            st.pop();
        ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}
```
