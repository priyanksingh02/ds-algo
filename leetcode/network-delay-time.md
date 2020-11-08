```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> adj(N+1);
        for(auto &v: times) {
            adj[v[0]].push_back(make_pair(v[1],v[2]));
        }
        const int inf = 1e9;
        vector<int> dist(N+1, inf);
        dist[K] = 0;
        set<pair<int,int>> s;
        s.insert(make_pair(dist[K],K));
        while(!s.empty()) {
            int u = s.begin()->second;
            s.erase(s.begin());
            for(auto & v: adj[u]) {
                if(dist[v.first] > dist[u] + v.second) {
                    if(dist[v.first] != inf) {
                        s.erase(s.find({dist[v.first],v.first}));
                    }
                    dist[v.first] = dist[u] + v.second;
                    s.insert(make_pair(dist[v.first], v.first));
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            if(dist[i] == inf)
                return -1;
            ans = max(dist[i], ans);
        }
        return ans;
    }
};

```

