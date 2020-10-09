```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0;
        int maxarea = 0;
        stack<int> st;
        for(; i < heights.size(); ++i) {
            while(!st.empty() and heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                if(st.empty())
                    maxarea = max(maxarea, heights[top]*(i));
                else
                    maxarea = max(maxarea, heights[top]*(i - st.top() - 1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(st.empty())
                maxarea = max(maxarea, heights[top]*i);
            else
                maxarea = max(maxarea, heights[top]*(i - st.top() - 1));
        }
        return maxarea;
    }
};
```
