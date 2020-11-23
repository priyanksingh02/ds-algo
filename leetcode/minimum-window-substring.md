```cpp
class Solution {
  public:
    string minWindow(string s, string t) {
      int minlen = 1e6, idx = 0;
      int i = 0, j = 0;
      vector<int> cnt(255, 0);
      for(char c: t) {
        cnt[c]++;
      }
      int total = t.size();
      while(j < s.size()) {
        if(--cnt[s[j]] >= 0)
          --total;
        while(total <= 0 && i <= j) {
          if(minlen > j - i + 1) {
            minlen = j - i + 1;
            idx = i;
          }
          if(++cnt[s[i]] > 0)
            ++total;
          i++;
        }
        j++;
      }
      if(minlen == 1e6)
        return "";
      return s.substr(idx, minlen);

    }
};
```
```cpp
class Solution {
  public:
    bool cover(const vector<int> & count) {
      for(int i = 0; i < count.size(); ++i) {
        if(count[i] > 0)
          return false;
      }
      return true;
    }
    string minWindow(string s, string t) {
      vector<int> count(255, 0);
      for(auto & x: t)
        count[x]++;
      int slow = 0, fast = 0;
      int ans = 1e9, pos = -1;
      while(fast < s.size()) {
        count[s[fast]]--;
        while(slow <= fast && cover(count)) {
          if(fast-slow+1 < ans) {
            ans = fast-slow + 1;
            pos = slow;
          }
          count[s[slow]]++;
          slow++;
        }
        fast++;
      }
      if(pos == -1)
        return "";
      return s.substr(pos, ans);
    }
};
```
