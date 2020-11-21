```cpp
vector <long long> nextLargerElement(long long arr[], int n){
    stack<long long> st;
    vector<long long> ans;
    for(int i = n-1; i >= 0; --i) {
        while(!st.empty() and st.top() <= arr[i]) {
            st.pop();
        }
        if(st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;
}
```

