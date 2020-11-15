```cpp
string reverseWords(string s) 
{
    vector<string> words;
    int i = 0;
    while(i < s.size()) {
        auto pos = s.find('.', i);
        if(pos == string::npos) {
            words.emplace_back(s.substr(i));
            i = s.size();
        }
        else {
            words.emplace_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    if(words.empty())
        return "";
    reverse(words.begin(), words.end());
    string ans;
    for(auto & s: words) {
        ans += s + ".";
    }
    ans.pop_back();
    return ans;
}

```
