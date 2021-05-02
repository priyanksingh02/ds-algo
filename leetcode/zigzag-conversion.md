```cpp
class Solution {
  public:
    string convert(string s, int numRows) {
      vector<string> pattern (numRows);
      bool dir = true; // true means down
      int pos = 0;
      if(numRows == 1)
        return s;

      for(char c: s) {
        pattern[pos].push_back(c);
        if(dir) {
          pos++;
          if(pos == numRows) {
            pos = numRows - 2;
            dir = false;
          }
        }
        else {
          pos--;
          if(pos == -1) {
            pos = 1;
            dir = true;
          }
        }
      }

      string res;
      for(int i = 0;i < numRows; ++i) {
        res += pattern[i];
      }
      return res;
    }
};
```
