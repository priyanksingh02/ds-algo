```cpp

bool valid(string & s) {
    if(s.empty() || s.size() > 3)
        return false;
    int n = stoi(s);
    if(n < 0 || n > 255)
        return false;
    if(to_string(n) != s)
        return false;
    return true;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    for(int i = 1; i <= 3; ++i) {
        string a = A.substr(0,i);
        if(valid(a) && i < A.size()) {
            for(int j = 1; j <= 3; ++j) {
                string b = A.substr(i, j);
                if(valid(b) && (i+j) < A.size()) {
                    for(int k = 1; k <= 3; ++k) {
                        if(i+j+k >= A.size())
                            continue;
                        string c = A.substr(i+j,k);
                        string d = A.substr(i+j+k);
                        if(valid(c) && valid(d)) {
                            ans.push_back(a+"."+b+"."+c+"."+d); 
                        }
                    }
                }
            }   
        }
    }
    return ans;
}
```

```cpp
bool valid(const string & s) {
    if(s.empty())
        return false;
    int val = stoi(s);
    if(s[0] == '0' && val)
        return false;
    if(s.size() > 1 && !val)
        return false;
    if(val >= 0 and val <= 255)
        return true;
    return false;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    string cur;
    for(int i = 1; i <= 3 && i <= A.size(); ++i) {
        string a= A.substr(0,i);
        if(valid(a)) {
            for(int j = 1; j <= 3 && i + j <= A.size(); ++j) {
                string b = A.substr(i,j);
                if(valid(b)) {
                    for(int k = 1; k <= 3 && i + j + k <= A.size(); ++k) {
                        string c = A.substr(i+j, k);
                        string d = A.substr(i+j+k);
                        if(valid(c) && valid(d)) {
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
                    }
                }
            }
        }
    }
    return ans;
}
```
