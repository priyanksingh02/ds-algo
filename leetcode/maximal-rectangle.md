```cpp
class Solution {
public:
    int maxrect(const vector<int> & arr) {
        stack<int> st;
        int maxarea = 0;
        for(int i = 0;i < arr.size(); ++i) {
            while(!st.empty() and arr[st.top()] >= arr[i]) {
                int h_idx = st.top();
                st.pop();
                if(st.empty())
                    maxarea = max(maxarea, arr[h_idx]*(i));
                else
                    maxarea = max(maxarea, arr[h_idx]*(i - st.top() - 1));
            }
            st.push(i);
        }
        int i = arr.size();
        while(!st.empty()) {
            int h_idx = st.top(); st.pop();
            if(!st.empty())
                maxarea = max(maxarea, arr[h_idx]*(i - st.top() - 1));
            else
                maxarea = max(maxarea, arr[h_idx]*(i));
        }
        return maxarea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() or matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea = 0;
        vector<int> row(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1')
                    row[j]++;
                else
                    row[j] = 0;
            }
            maxarea = max(maxarea, maxrect(row));
        }
        return maxarea;
    }
};

```
```cpp
class Solution {
public:
    
    int width(vector<int> & row) {
        int cur = 0;
        int maxwidth = 0;
        for(int i= 0; i < row.size(); ++i) {
            if(row[i]) {
                ++cur;
            }
            else {
                cur = 0;
            }
            maxwidth = max(maxwidth, cur);
        }
        return maxwidth;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() or matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea = 0;
        for(int i = 0; i < m; ++i) {
            vector<int> row(n, 1);
            for(int j = i; j < m; ++j) {
                for(int k = 0; k < n; ++k) {
                    row[k] &= (matrix[j][k] - '0');
                }
                maxarea = max(maxarea, width(row)*(j-i+1)); // height = j-i+1
            }
        }
        return maxarea;
    }
};
```

