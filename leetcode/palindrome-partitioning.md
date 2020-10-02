```cpp
class Solution {
    vector<vector<bool>> is_pal;
    vector<vector<string>> ans;
public:
    void gen(string& s, int pos, vector<string> & row) {
        if(pos == s.size()) {
            ans.push_back(row);
            return;
        }
        for(int i = pos; i < s.size(); ++i) {
            if(is_pal[pos][i]) {
                row.push_back(s.substr(pos, i-pos + 1));
                gen(s, i+1, row);
                row.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        is_pal.resize(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) {
                    is_pal[i][j] = true;
                }
                else if(s[i] == s[j]) {
                    if(i+1 <= j - 1)
                        is_pal[i][j] = is_pal[i+1][j-1];
                    else
                        is_pal[i][j] = true;
                }
                else 
                    is_pal[i][j] = false;
            }
        }
        vector<string> row;
        gen(s, 0, row);
        return ans;
    }
};
```
