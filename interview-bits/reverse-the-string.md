```cpp

string Solution::solve(string A) {
    stringstream ss {A};
    string word;
    vector<string> words;
    while(ss >> word) {
        words.emplace_back(word);
    }
    reverse(words.begin(), words.end());
    string ans;
    for(auto & w: words) {
        ans += w + " ";
    }
    ans.pop_back();
    return ans;
}
```
