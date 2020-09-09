```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss {s};
        string word;
        vector<string> words;
        while(ss>> word) {
            words.push_back(word);
        }
        reverse(words.begin(),  words.end());
        string ans;
        for(auto & w: words) {
            ans += w + " ";
        }
        if(!ans.empty())
            ans.pop_back();
        return ans;
    }
};
```
