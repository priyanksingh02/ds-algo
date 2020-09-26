```cpp

#include <tuple>
vector<vector<int> > Solution::threeSum(vector<int> &A) {
  set<pair<pair<int,int>,int>> s;
  sort(A.begin(), A.end());
  for(int i = 0; i < A.size(); ++i) {
    int j = i+1;
    int k = (int)A.size() -1;
    while(j < k) {
      long sum = (long)A[i] + A[j] + A[k];
      if(sum == 0) {
        s.insert({{A[i],A[j]},A[k]});
        j++;
        k--;
      }
      else if(sum > 0) {
        k--;
      }
      else {
        j++;
      }
    }
  }
  vector<vector<int>> ans;
  for(auto & x: s) {
    ans.push_back({x.first.first, x.first.second,x.second});
  }
  return ans;
}

```
```cpp
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    set<tuple<int,int,int>> s;
    for(int i = 0; i < (int)A.size() - 2; ++i) {
        int j = i + 1;
        int k = A.size() - 1;
        while(j < k) {
            if((long long)A[k] + A[j] == -(long long)A[i]) {
                s.insert({A[i],A[j],A[k]});
                j++;
                k--;
            }
            else if((long long)A[j] + A[k] > -(long long)A[i])
                k--;
            else
                j++;
        }
    }
    vector<vector<int>> ans;
    for(auto & x: s) {
        int i,j,k;
        tie(i,j,k) = x;
        ans.push_back({i,j,k});
    }
    return ans;
}
```
