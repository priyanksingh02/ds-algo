## Word Ladder I
Problem link:
https://www.interviewbit.com/problems/word-ladder-i/
```cpp
int Solution::solve(string A, string B, vector<string> &C) {
    vector<pair<string, vector<int>>> adjlist (C.size() + 2);
    adjlist[0].first = A;
    adjlist[1].first = B;
    for(int i = 0; i < C.size(); ++i) {
        adjlist[i+2].first = C[i];
    }
    int n = C.size() + 2;
    auto onediff = [](string & a, string & b) {
        int diff = 0;
        // given a and b are of equal length
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                if(++diff > 1)
                    return false;
            }
        }
        return true;
    };
    
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(onediff(adjlist[i].first, adjlist[j].first)) {
                adjlist[i].second.push_back(j);
                adjlist[j].second.push_back(i);
            }
        }
    }
    //find shortest path between 0 and 1 using bfs
    queue<pair<int, int>> q;
    vector<bool> visited (n, false);
    q.push({0,1});
    visited[0] = true;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int u = p.first;
        int path = p.second;
        for(auto & v: adjlist[u].second) {
            if(!visited[v]) {
                if(v == 1) {
                    return path + 1;
                }
                visited[v] = true;
                q.push({v, path+1});
            }
        }
    }
    return -1;
}
```
