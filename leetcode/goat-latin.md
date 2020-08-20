```cpp
class Solution {
public:
    bool vowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u': 
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
        }
        return false;
    }
    string convert(int& count, string s) {
        string ans;
        if(!vowel(s[0])) {
            for(int i = 1; i < s.size(); ++i) {
                ans += s[i];
            }
            ans += s.front();
        }
        else {
            ans += s;
        }
        ans += "ma";
        ans += string(count, 'a');
        ++count;
        return ans;
    }
    string toGoatLatin(string S) {
        int i = 0;
        int count = 1;
        string ans;
        while(i < S.size()) {
            int pos = S.find(' ', i);
            string s = S.substr(i, pos - i);
            if(s.empty()) {
                i = pos+1;
                continue;
            }
            if(!ans.empty())
                ans += " ";
            ans += convert(count,s);
            if(pos == string::npos) {
                break;
            }
            i = pos + 1;
        }
        return ans;
    }
};
```

Using string stream

```cpp

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream st(S);
        string word, ans;
        int count = 1;
        unordered_set<char> vowel { 'a', 'e', 'i', 'o', 'u'};
        while(st >> word) {
            if(!ans.empty())
                ans += " ";
            if(!vowel.count(tolower(word.front()))) {
                word = word.substr(1) + word.front();
            }
            ans += word + "ma" + string(count++,'a');
        }
        return ans;
    }
};
```
