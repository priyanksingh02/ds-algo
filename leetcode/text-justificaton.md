```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while(i < words.size()) {
            vector<string> cur;
            int len = 0;
            while(len < maxWidth && i < words.size()) {
                if(cur.empty() || words[i].size() + len + 1<= maxWidth) {
                    if(!cur.empty())
                        len++;
                    cur.push_back(words[i]);
                    len += words[i].size();
                    i++;
                }
                else
                    break;
            }
            int spare = maxWidth - len;
            string row;
            if(spare > 0 && cur.size() > 1 && i < words.size()) {
                int def_space = spare/((int)cur.size() - 1);
                int left_space = spare%((int)cur.size() - 1);
                for(int i = 0; i < cur.size(); ++i) {
                    if(!row.empty()) {
                        if(left_space-- > 0) {
                            row += string(def_space+2,' ');
                        }
                        else
                            row += string(def_space+1, ' ');
                    }
                    row+= cur[i];
                }
            }
            else {
                for(int i = 0; i < cur.size(); ++i) {
                    if(!row.empty())
                        row+= ' ';
                    row+=cur[i];
                }
                if(row.size() < maxWidth) {
                    row += string(maxWidth - row.size(), ' ');
                }
            }
            ans.push_back(row);
            cur.clear();
        }
        return ans;
    }
};
```
