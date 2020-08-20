```cpp
class Solution {
public:
    void dfs(vector<vector<int>> & adj, int i, vector<int> & ans, int val, int len, int N) {
        val = val*10 + i;
        if(++len == N) {
            ans.push_back(val);
            return;
        }
        for(auto & v: adj[i]) {
            dfs(adj, v, ans, val, len, N);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        //construct graph
        vector<vector<int>> adjlist (10);
        for(int i = 0; i < 10; ++i) {
            if(i+k >= 0 && i+k <= 9) {
                adjlist[i].push_back(i+k);
                if(i != i+k) // do not add same node twice
                    adjlist[i+k].push_back(i);
            }
        }
        //starting from every node except 0
        //return a with size N
        vector<int> ans;
        for(int i = 1; i < 10; ++i) {
            dfs(adjlist, i, ans, 0, 0, n);
        }
        if(n == 1)
            ans.push_back(0);
        return ans;
    }
};
```
