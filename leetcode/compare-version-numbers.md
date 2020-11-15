```cpp
class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        int i  = 0, j = 0;
        bool l1 = false, l2 = false;
        while(i < version1.size() or j < version2.size()) {
            auto p1 = version1.find('.', i);
            int s1 = 0, s2 = 0;
            if(p1 != string::npos) {
                s1 = stoi(version1.substr(i, p1 - i));
                i = p1 + 1; 
            }
            else if(!l1) {
                s1 = stoi(version1.substr(i));
                i = version1.size();
                l1 = true;
            }
            auto p2 = version2.find('.', j);
            if(p2 != string::npos) {
                s2 = stoi(version2.substr(j, p2 - j));
                j = p2 + 1;
            }
            else if(!l2) {
                s2 = stoi(version2.substr(j));
                j = version2.size();
                l2 = true;
            }
            if(s1 < s2)
                return -1;
            else if(s1 > s2)
                return 1;
        }
        return 0;
    }
};
```

