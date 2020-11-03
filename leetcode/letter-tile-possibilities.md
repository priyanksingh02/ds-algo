Brute force Approach as constraint was `tiles.length <= 7`
```cpp
class Solution {
  set<string> ans;
public:
  
  vector<string> all(string & a) {
    sort(a.begin(), a.end());
    vector<string> ans;
    do {
      ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));
    return ans;
  }
  
  int numTilePossibilities(string tiles) {
    int limit = (1 << tiles.size());
    int n = tiles.size();
    for(int i = 1; i < limit; ++i) {
      string tmp;
      for(int j = 0; j < n; ++j) {
        if(i&(1<<j)) {
          tmp.push_back(tiles[j]); 
        }
      }
      for(auto & s: all(tmp)) {
        ans.insert(s);
      }
    }
    return ans.size();
  }
};
```
