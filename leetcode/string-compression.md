```cpp
class Solution {
  public:
    int compress(vector<char>& chars) {
      vector<pair<char, int>> ans;
      for(int i = 0; i < chars.size(); ++i) {
        if(ans.empty() or ans.back().first != chars[i]) {
          ans.push_back({chars[i], 1});
        }
        else {
          ans.back().second++;
        }
      }
      chars.clear();
      for(int i = 0; i < ans.size(); ++i) {
        chars.push_back(ans[i].first);
        if(ans[i].second == 1) continue;
        string num = to_string(ans[i].second);
        for(int j = 0; j < num.size(); ++j) {
          chars.push_back(num[j]);
        }
      }
      return chars.size();
    }
};

```
