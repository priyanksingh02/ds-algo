```cpp
string Solution::solve(string A) {
    vector<int> count(26, 0);
    queue<char> q;
    string ans;
    for(int i = 0; i < A.size(); ++i) {
        if(count[A[i] - 'a'] == 0) {
            q.push(A[i]);
        }
        count[A[i] - 'a']++;
        while(!q.empty() && count[q.front() - 'a'] > 1)
            q.pop();
        if(q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}
```
