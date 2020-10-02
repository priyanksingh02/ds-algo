
Heap Solution
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using iii = pair<int,pair<int,int>>;
        priority_queue<iii, vector<iii>, greater<iii>> min_heap;
        int n = matrix.size();
        for(int i = 0; i < n; ++i) { // fill with 1st col
            min_heap.push({matrix[i][0],{i,0}});
        }
        int ans = 0;
        while(k--) {
            ans = min_heap.top().first;
            int row = min_heap.top().second.first;
            int col = min_heap.top().second.second;
            min_heap.pop();
            if(col + 1 < n) {
                min_heap.push({matrix[row][col+1], {row, col+1}});
            }
        }
        return ans;
    }
};

```
Binary Search solution
```cpp
class Solution {
public:
    int left(vector<vector<int>> & matrix, int target) {
        int count = 0;
        int row = (int)matrix.size() - 1;
        int col = 0;
        while(row >= 0 and col < matrix.size()) {
            if(matrix[row][col] <= target) {
                count += row + 1;
                col++;
            }
            else {
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high) {
            int mid = low + (high - low >> 1);
            if(left(matrix, mid) >= k) {
                high= mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

```
O(n^2 logn)
Heap Solution
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() or matrix.back().empty())
            return 0;
        priority_queue<int> pq;
        for(int i= 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix.size(); ++j) {
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
```
