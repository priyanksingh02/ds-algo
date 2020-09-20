```cpp
string gen(const string & s, int level) {
    return string(level, '\t') + s;
}

vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;
    string row;
    int level = 0;
    for(int i= 0; i < A.size(); ++i) {
        if(A[i] == ' ')
            continue;
        else if(A[i] == '\t')
            ++level;
        else if(A[i] == '{' || A[i] == '[') {
            if(!row.empty())
                ans.push_back(gen(row, level));
            ans.push_back(gen(string(1,A[i]), level));
            ++level;
            row.clear();
        }
        else if(A[i] == ']' || A[i] == '}') {
            if(!row.empty())
                ans.push_back(gen(row, level));
            --level;
            if(i + 1 < A.size() && A[i+1] == ',') {
                string tmp = string(1,A[i]);
                tmp.push_back(',');
                ans.push_back(gen(tmp, level));
                i++;
            }
            else 
                ans.push_back(gen(string(1,A[i]), level));
            row.clear();
        }
        else if(A[i] == ',') {
            row.push_back(',');
            ans.push_back(gen(row, level));
            row.clear();
        }
        else {
            row.push_back(A[i]);
        }
    }
    return ans;
}
```
