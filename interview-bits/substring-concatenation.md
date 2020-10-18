```cpp

bool check(const string & s, const vector<string> & words) {   
    int l = words.front().size();
    unordered_map<string,int> st;
    for(int i = 0; i < s.size(); i+=l) {
        st[s.substr(i, l)]++;
    }
    for(auto & word: words) {
        if(!st.count(word) or --st[word] < 0)
            return false;
    }
    return true;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    if(A.empty() or B.empty())
        return {};
    int n = B.size();
    int l = B[0].size();
    int len = n*l;
    vector<int> ans;
    for(int i = len; i <= A.size(); ++i) {
        if(check(A.substr(i-len,len), B)) {
            ans.push_back(i-len);
        }
    }
    return ans;
}
```
