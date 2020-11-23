```cpp
class Solution {
  int ans;
  public:

  void solve(vector<string> & arr, int pos, unordered_set<char> & cur, int len) {
    ans = max(ans, len);
    if(pos == arr.size()) {     
      return;
    }
    bool possible = true;
    for(int i = 0; i < arr[pos].size(); ++i) {
      if(cur.count(arr[pos][i])) {
        possible = false;
        break;
      }
    }
    if(possible) {
      for(int i = 0; i < arr[pos].size(); ++i) {
        cur.insert(arr[pos][i]);
      }
      solve(arr, pos+1, cur, len + arr[pos].size());
      for(int i = 0; i < arr[pos].size(); ++i) {
        cur.erase(arr[pos][i]);
      }
    }

    solve(arr, pos+1, cur, len);

  }

  int maxLength(vector<string>& arr) {
    ans = 0;
    if(arr.empty())
      return ans;
    vector<string> arr2;
    for(int i = 0; i < arr.size(); ++i) {
      if(arr[i].size() < 27) {
        unordered_set<char> rep;
        bool uniq = true;
        for(int j = 0; j < arr[i].size(); ++j) {
          if(!rep.insert(arr[i][j]).second) {
            uniq = false;
            break;
          }
        }
        if(uniq)
          arr2.emplace_back(arr[i]);
      }
    }
    unordered_set<char> cur;
    solve(arr2, 0, cur , 0);
    return ans;
  }
};
```
```cpp
class Solution {
  int ans;
  public:

  void solve(vector<string> & arr, int pos, unordered_set<char> cur, int len) {
    ans = max(ans, len);
    if(pos == arr.size()) {
      return ;
    }
    for(int i = pos; i < arr.size(); ++i) {
      bool possible = true;
      for(int j= 0;j < arr[i].size(); ++j) {
        if(cur.count(arr[i][j])) {
          possible = false;
          break;
        }
      }
      if(possible) {
        for(int j = 0; j < arr[i].size(); ++j) {
          cur.insert(arr[i][j]);
        }
        solve(arr, i + 1, cur, len + arr[i].size());
        for(int j = 0; j < arr[i].size(); ++j) {
          cur.erase(arr[i][j]);
        }
      }
    }
  }

  int maxLength(vector<string>& arr) {
    ans = 0;
    if(arr.empty())
      return ans;
    vector<string> arr2;
    for(int i = 0; i < arr.size(); ++i) {
      if(arr[i].size() < 27) {
        unordered_set<char> rep;
        bool uniq = true;
        for(int j = 0; j < arr[i].size(); ++j) {
          if(!rep.insert(arr[i][j]).second) {
            uniq = false;
            break;
          }
        }
        if(uniq)
          arr2.emplace_back(arr[i]);
      }
    }
    solve(arr2, 0, {} , 0);
    return ans;
  }
};

```
