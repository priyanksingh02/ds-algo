```cpp

void gen(vector<int> &A, int pos, int cursum, int target, vector<int> & cur, vector<vector<int>> & ans) {
    if(pos == A.size()) {
        return ;
    }
    if(A[pos] + cursum == target) {
        cur.push_back(A[pos]);
        ans.push_back(cur);
        cur.pop_back();
        return;
    }
    if(A[pos] + cursum < target) {
        cur.push_back(A[pos]);
        gen(A, pos, cursum + A[pos],target, cur, ans);
        cur.pop_back();
    }
    gen(A,pos+1, cursum, target, cur, ans);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) {
    sort(A.begin(), A.end());
    A.resize(distance(A.begin(),unique(A.begin(), A.end())));
    vector<vector<int>> ans;
    vector<int> cur;
    gen(A, 0, 0, target, cur, ans);
    return ans;
}
```
## Combination Sum II
```cpp
void gen(const vector<int> & arr, int i, int sum, int target, vector<int> & cur, 
    set<vector<int>> & ans) {
        if(i == arr.size())
            return ;
        if(arr[i] + sum == target) {
            cur.push_back(arr[i]);
            ans.insert(cur);
            cur.pop_back();
            return;
        }
        if(arr[i] + sum < target) {
            cur.push_back(arr[i]);
            gen(arr, i+1, sum+arr[i], target, cur, ans);
            cur.pop_back();
        }
        gen(arr, i+1, sum, target, cur, ans);
    }

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int target) {

    sort(arr.begin(), arr.end());
    set<vector<int>> ans;
    vector<int> cur;
    gen(arr, 0, 0, target, cur, ans);
    return {ans.begin(), ans.end()};
}

```
