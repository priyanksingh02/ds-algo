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
## Word Ladder II
Using DFS
```cpp

void dfs(int src, int dest, vector<vector<int>> & ans, vector<bool> & visited,
    vector<int> & cur, vector<vector<int>> & adjlist) {
    if(src == dest) {
        cur.push_back(dest);
        ans.push_back(cur);
        cur.pop_back();
        return ;
    }
    visited[src] = true;
    for(auto & v: adjlist[src]) {
        if(!visited[v]) {
            cur.push_back(src);
            // cout << src << "->" << v << endl;
            dfs(v, dest, ans,visited, cur, adjlist);
             cur.pop_back();
        }
    }
    visited[src] = false;
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(start == end)
        return {{start}};
    map<string, int> words;
    int idx = 1;
    for(auto & x: dict) {
        if(words[x] == 0)
            words[x] = idx++;
    }
    int n = words.size() + 1; // 1 based indexing
    vector<vector<int>> adjlist(n);
    auto onediff = [](const string & a,const string & b) {
        int diff = 0;
        assert(a.size() == b.size());
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                ++diff;
            }
        }
        return diff == 1;
    };
    for(auto & w: words) {
        for(auto & x: words) {
            if(onediff(w.first,x.first)) {
                adjlist[w.second].push_back(x.second);
            }
        }
    }
    
    // for(int i = 0; i < adjlist.size(); ++i) {
    //     cout << i << ":";
    //     for(auto & y: adjlist[i]) {
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> nums;
    vector<int> path;
    vector<bool> visited(n, false);
    dfs(words[start], words[end], nums, visited, path, adjlist);
    // for(auto & x: nums) {
    //     for(auto & y: x)
    //         cout << y << " ";
    //     cout <<endl;
    // }
    vector<vector<string>> ans;
    unordered_map<int, string> m;
    for(auto & x: words) {
        m[x.second] = x.first;
    }
    int plen = INT_MAX;
    for(int i = 0; i< nums.size(); ++i) {
        if(plen < nums[i].size())
            continue;
        if(plen > nums[i].size()) {
            plen = nums[i].size();
            ans.clear();
        }
        vector<string> spath;
        for(int j = 0; j< nums[i].size(); ++j) {
            spath.push_back(m[nums[i][j]]);
        }
        ans.push_back(spath);
    }
    return ans;
}
```
Using BFS

```cpp


```
