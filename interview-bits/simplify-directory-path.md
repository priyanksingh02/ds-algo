```cpp

string Solution::simplifyPath(string A) {
    vector<string> st;
    if(A.empty())
        return "";
    for(int i= 1; i < A.size(); ++i) {
        auto it = A.find('/',i);
        if(it != string::npos) {
            string folder = A.substr(i, it - i);
            if(folder.empty() or folder == ".") {
                // do nothing
            }
            else if(folder == "..") {
                if(!st.empty()) st.pop_back();
            }
            else {
                st.push_back(folder);
            }
            i = it;
        }
        else {
            string folder = A.substr(i);
            if(folder == ".") {
                // do nothing
            }
            else if(folder == ".." ) {
                if(!st.empty()) st.pop_back();
            }
            else {
                st.push_back(folder);
            }
            i = A.size();
        }
    }
    string ans;
    for(auto & s: st) {
        ans += "/" + s;
    }
    if(ans.empty())
        return "/";
    return ans;
}
```
