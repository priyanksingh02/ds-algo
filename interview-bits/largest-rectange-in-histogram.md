```cpp

int Solution::largestRectangleArea(vector<int> &A) {
    int n=A.size(),max=0,area;
    vector<int> L(n,1);         //Left Side of Histogram
    vector<int> R(n,1);         //Right Side of Histogram
    
    for(int i=0;i<n;i++) 
        while(i-L[i]>-1&&A[i-L[i]]>=A[i]) 
            L[i]+=L[i-L[i]];
    
    for(int i=n-1;i>-1;i--){
        while(i+R[i]<n&&A[i+R[i]]>=A[i]) 
            R[i]+=R[i+R[i]];
        
        area=A[i]*(L[i]+R[i]-1);
        if(max<area) max=area;
    }
    
    return max;
}

```


```cpp

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st;
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        while(!st.empty() && A[st.top()] >= A[i]) {
            int height = A[st.top()];
            st.pop();
            if(st.empty()) {
                ans = max(ans, height*i);
            }
            else {
                ans = max(ans, height*(i - st.top() - 1));
            }
        }
        st.push(i);
    }
    int i = A.size();
    while(!st.empty()) {
        int height = A[st.top()];
        st.pop();
        if(st.empty())
            ans = max(ans, i* height);
        else
            ans = max(ans, height * (i - st.top() - 1));
    }
    return ans;
  
}
```
