```cpp
class Solution {
  public:
    vector<int> shortestToChar(string s, char c) {
      const int inf = 1e5;
      vector<int> ans (s.size(), inf);
      for(int i = 0; i < s.size(); ++i) {
        if(s[i] == c)
          ans[i] = 0;
      }
      for(int i= 1;i < ans.size(); ++i) {
        ans[i] = min(ans[i], ans[i-1] + 1);
      }
      for(int i = (int)ans.size() - 2; i >= 0; --i) {
        ans[i] = min(ans[i], ans[i+1] + 1);
      }
      return ans;
    }
};
```
