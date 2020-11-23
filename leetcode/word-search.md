## Word Search
```cpp
class Solution {
    vector<pair<int,int>> direction {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> visited;
public:
    bool dfs(vector<vector<char>> & board, int i, int j, string & word, int pos) {
        if(pos == word.size())
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if(visited[i][j] || board[i][j] != word[pos])
            return false;
        visited[i][j] = true;
        for(auto & d: direction) {
            if(dfs(board, i+d.first, j+d.second, word, pos+1))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == word[0]) {
                    visited.clear();
                    visited.resize(m, vector<bool>(n, false));
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
```
## Word Search II
```cpp
struct node {
    bool leaf = false;
    unordered_map<char, node*> child;  
};

void insert(node* root, const string & s) {
    for(const char & c: s) {
        if(!root->child.count(c))
            root->child[c] = new node();
        root = root->child[c];
    }
    root->leaf =true;
}

class Solution {
public:
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};
    
    bool valid(int r, int c, int R, int C) {
        return r >= 0 and c >= 0 and r < R and c < C;
    }
    
    void dfs(int r, int c, vector<vector<char>> & board, node * root, string & cur, vector<string> & ans) {
        if(root->leaf) {
            root->leaf = false;
            ans.push_back(cur);
        }
        char backup = board[r][c];
        board[r][c] = '#';
        int R = board.size();
        int C = board[0].size();
        for(int i = 0; i < 4; ++i) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(valid(x, y, R, C) && root->child.count(board[x][y])) {
                cur.push_back(board[x][y]);
                dfs(x, y, board, root->child[board[x][y]], cur, ans);
                cur.pop_back();
            }
        }
        board[r][c] = backup;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() or board[0].empty()) return {};
        int R = board.size();
        int C = board[0].size();
        
        node * root = new node();
        for(auto & w: words) {
            insert(root, w);
        }
        vector<string> ans;
        string cur;
        
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(root->child.count(board[i][j])) {
                    cur.push_back(board[i][j]);
                    dfs(i, j, board, root->child[board[i][j]], cur, ans);
                    cur.pop_back();
                }
            }
        }
        return ans;
    }
};
```
```cpp
struct node {
    bool is_leaf;
    map<char, node *> chars;
    node(): is_leaf(false) {};
};

void insert(node * root, const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        if(!root->chars.count(s[i]))
            root->chars[s[i]] = new node();
        root = root->chars[s[i]];
    }
    root->is_leaf = true;
}

class Solution {
    vector<string> ans;
    vector<vector<bool>> visited;
    vector<pair<int, int>> direction {{1,0},{0,1},{-1,0},{0,-1}};
public:
    void dfs(vector<vector<char>> & board, int r, int c, node * root, string & word) {
        if(r < 0 or c < 0 or r >= board.size() or c >= board[0].size() or !root 
           or visited[r][c] or !root->chars.count(board[r][c]))
            return ;
        visited[r][c] = true;
        root = root->chars[board[r][c]];
        word.push_back(board[r][c]);
        if(root->is_leaf) {
            ans.push_back(word);
            root->is_leaf = false;
        }
        for(auto & d: direction) {
            dfs(board, r+d.first, c + d.second, root, word);
        }
        word.pop_back();
        visited[r][c] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() or board.front().empty())
            return {};
        node * root = new node();
        for(auto & w: words)
            insert(root, w);
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(root->chars.count(board[i][j])) {
                    visited.clear();
                    visited.resize(m, vector<bool> (n, false));
                    string word;
                    dfs(board, i, j, root, word);
                }
            }
        }
        return ans;
    }
};
```
