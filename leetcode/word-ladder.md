## Word Ladder
```cpp
class Solution {
public:
    bool one_diff(const string & a, const string & b) {
        int dif = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i] && ++dif > 1)
                return false;
        }
        return dif == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        int src = n - 1;
        int dest = -1;
        for(int i= 0; i < n; ++i) {
            if(wordList[i] == endWord) {
                dest = i;
                break;
            }
        }
        if(dest == -1)
            return 0; // endword not in wordlist
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(one_diff(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<pair<int,int>> q;
        vector<bool> visited(n, false);
        q.push({src, 1});
        visited[src] = true;
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int u = p.first;
            int len = p.second;
            for(auto & v: adj[u]) {
                if(v == dest) {
                    return len + 1;
                }
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, len+1});
                }
            }
        }
        return 0;
    }
};
```
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<pair<string, vector<int>>> adj(n+1);
        adj[0].first = beginWord;
        bool present = false;
        int pos = -1;
        for(int i = 0; i < n; ++i) {
            adj[i+1].first = wordList[i];
            if(wordList[i] == endWord) {
                present = true;
                pos = i+1;
            }
        }
        if(!present)
            return 0;
        auto is_connected = [](string & a, string & b) {
            int diff = 0;
            for(int i = 0; i < a.size(); ++i) {
                if(a[i] != b[i])
                    ++diff;
                if(diff > 1)
                    return false;
            }
            return diff == 1;
        };
        for(int i = 0; i < adj.size(); ++i) {
            for(int j = i+1; j < adj.size(); ++j) {
                if(is_connected(adj[i].first, adj[j].first)) {
                    adj[i].second.push_back(j);
                    adj[j].second.push_back(i);
                }
            }
        }
        queue<pair<int, int>> q;
        vector<bool> visited (n+1, false);
        q.push({0, 1});
        visited[0] = true;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int u = p.first;
            int len = p.second;
            for(auto & v: adj[u].second) {
                if(v == pos) // final
                    return len + 1;
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, len+1});
                }
            }
        }

        return 0; // unreachable

    }
};
```

## Word Ladder II

```cpp
class Solution {
public:
    bool is_connected(string & a, string & b) {
        int diff = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i] && ++diff > 1) 
                return false;
        }
        return diff == 1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n= wordList.size();
        vector<pair<string, vector<int>>> adj(n + 1);
        adj[0].first = beginWord;
        int endpos = -1;
        int present = false;
        for(int i = 0; i < n; ++i) {
            adj[i+1].first = wordList[i];
            if(endWord == wordList[i]) {
                present = true;
                endpos = i+1;
            }
        }
        if(!present)
            return {};
        for(int i = 0; i < adj.size(); ++i) {
            for(int j = i + 1; j < adj.size(); ++j) {
                if(is_connected(adj[i].first,adj[j].first)) {
                    adj[i].second.push_back(j);
                    adj[j].second.push_back(i);
                }
            }
        }
        vector<vector<string>> ans;
        int max_len = INT_MAX;
        queue<pair<int, vector<string>>> q;
        vector<bool> visited(n+1, false);
        q.push({0, {adj[0].first}});
        while(!q.empty()) {

            auto p = q.front();
            q.pop();
            int u = p.first;
            auto & l = p.second;
            if(l.size() < max_len) {
                for(auto & v: adj[u].second) {
                    if(v == endpos) {
                        max_len = min(max_len, (int)l.size() + 1);
                        l.push_back(adj[v].first);
                        ans.push_back(l);
                        l.pop_back();
                    }
                    if(!visited[v]) {
                        l.push_back(adj[v].first);
                        q.push({v, l});
                        l.pop_back();
                    }
                }
            }
            visited[u] = true;
        }
        
        return ans;
    }
};

```
