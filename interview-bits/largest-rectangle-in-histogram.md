```cpp

int Solution::largestRectangleArea(vector<int> &height) {
    stack<int> st;
    int maxarea = 0;
    int i = 0;
    int n = height.size();
    for(; i < n; ++i) {
        while(!st.empty() and height[st.top()] > height[i]) {
            int pos = st.top();
            st.pop();
            if(st.empty()) {
                maxarea = max(maxarea, height[pos]*(i));
            }
            else {
                maxarea = max(maxarea, height[pos]*(i - st.top() - 1));
            }
        }
        st.push(i);
    }
    while(!st.empty()) {
        int pos = st.top();
        st.pop();
        if(st.empty()) {
            maxarea = max(maxarea, height[pos]*i);
        }
        else {
            maxarea = max(maxarea, height[pos]*(i - st.top() - 1));
        }
    }
    return maxarea;
}
```
