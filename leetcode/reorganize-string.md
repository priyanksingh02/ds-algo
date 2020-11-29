```cpp
class Solution {
  public:
    string reorganizeString(string S) {
      if(S.empty()) return "";
      int n = S.size();
      vector<int> cnt(256, 0);
      for(char c: S) {
        cnt[c]++;
      }
      vector<char> alpha;
      for(int i = 0; i < cnt.size(); ++i) {
        if(cnt[i] > 0)
          alpha.push_back(i);
      }
      sort(alpha.begin(), alpha.end(), [&](char a, char b) {
          return cnt[a] > cnt[b];
          });
      int sz = cnt[alpha[0]];
      vector<string> segments(sz, string(1, alpha[0]));
      int k =0;
      for(int i = 1; i < alpha.size(); ++i) {
        int limit = cnt[alpha[i]];
        for(int j = 0; j < limit; ++j) {
          segments[k].push_back(alpha[i]);
          k = (k + 1)%sz;
        }
      }
      string ans;
      for(int i = 0; i < segments.size(); ++i) {
        ans += segments[i];
      }
      bool possible = true;
      for(int i = 1; i < ans.size(); ++i) {
        if(ans[i] == ans[i-1]) {
          possible = false;
          break;
        }
      }
      if(possible) return ans;
      else return "";
    }
};
```
