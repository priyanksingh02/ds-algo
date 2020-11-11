```cpp
class Solution {
  public:
    string addBoldTag(string s, vector<string>& dict) {
      vector<bool> pos(s.size(), false);
      for(int i = 0; i < s.size(); ++i) {
        for(string &str: dict) {
          if(str[0] == s[i]) {
            bool found = true;
            int j = 0;
            for(; j < str.size() && i+j  < s.size() ; ++j) {
              if(str[j] != s[i+j]) {
                found = false;
                break;
              }
            }
            if(i+j == s.size() && j != str.size())
              found = false;
            if(found) {
              for(int j = 0; j < str.size() && i+j < s.size() ; ++j) {
                pos[i+j] = true;
              }
            }
          }
        }
      }
      bool prev = false;
      string ans;
      for(int i = 0; i < pos.size(); ++i) {
        if(prev == false && pos[i] == true) {
          ans += "<b>";
        }
        if(prev == true && pos[i] == false) {
          ans += "</b>";
        }
        ans.push_back(s[i]);
        prev = pos[i];
      }
      if(prev == true) {
        ans += "</b>";
      }
      return ans;
    }
};

```
