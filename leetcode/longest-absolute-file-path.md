```cpp
class Solution {
public:
    bool is_file(string& a) {
        return find(a.begin(), a.end(), '.') != a.end();
    }
    int lengthLongestPath(string s) {
        int n = s.size();
        int i = 0;
        vector<string>  path;
        int ans = 0;
        while(i < n) {
            int level = 0;
            if(s.substr(i, 1) == "\n") {
                i+=1;
            }
            while(s.substr(i,1) == "\t") {
                ++level;
                i+=1;
            }
            // cout << "level is " << level << endl;
            auto pos = s.find("\n", i);
            if(pos != string::npos) {
                string name = s.substr(i, pos - i);
                while(!path.empty() && path.size() > level) {
                    path.pop_back();
                }
                path.push_back(name);
                i = pos;
            }
            else {
                string name = s.substr(i);
                while(!path.empty() && path.size() > level) {
                    path.pop_back();
                }
                path.push_back(name);
                i = n;
            }
            if(!path.empty() and is_file(path.back())) {
                int len = (int)path.size() - 1;
                for(auto & x: path)
                    len += x.size();
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
```

