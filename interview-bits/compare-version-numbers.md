```cpp
string strip(const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != '0') {
            return s.substr(i);
        }
    }
    return "0";
}

pair<string, string> extract(const string & a) {
    if(a.empty())
        return {"0","0"};
    string rem = "0", cur;
    auto pos = a.find('.');
    if(pos == string::npos) {
        cur = a;
    }
    else {
        cur = a.substr(0, pos);
        rem = a.substr(pos+1);
    }
    return {strip(cur), rem};
}

int compare(const string & a, const string & b) {
    if(a.size() < b.size()) {
        return -1;
    }
    else if(a.size() > b.size()) {
        return 1;
    }
    else {
        if(a == b)
            return 0;
        else if(a < b) {
            return -1;
        }
        else {
            return 1;
        }
    }
}

int Solution::compareVersion(string A, string B) {
    if(A == "0" && B == "0")
        return 0;
    auto a = extract(A);
    auto b = extract(B);
    // cout << "A is " << A << " " << a.first << " " << a.second << endl;
    // cout << "B is " << B << " " << b.first << " " << b.second << endl;
    int ans = compare(a.first,b.first);
    if(ans == 0)
        return compareVersion(a.second, b.second);
    else
        return ans;
}
```

```python
class Solution:
	def compareVersion(self, A, B):
        a = [int(i) for i in A.split('.')]
        # a = list(map(int, A.split('.')))
        b = [int(i) for i in B.split('.')]
        n = max(len(a),  len(b))
        for i in range(n):
            left = 0
            right = 0
            if(i < len(a)):
                left = a[i]
            if(i < len(b)):
                right = b[i]
            if(left < right): 
                return -1
            if(right < left): 
                return 1
        return 0
```
