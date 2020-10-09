## Word Break
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i < dp.size(); ++i) {
            if(dp[i]) {
                for(int j = 0; j < wordDict.size(); ++j) {
                    int lim = wordDict[j].size();
                    if(i + lim < dp.size() && s.substr(i, lim) == wordDict[j])
                        dp[i+lim]= true;
                }
            }
        }
        return dp[n];
    }
};

```
## Word Break II
Memoization of overlapping solutions
```cpp
class Solution {
    unordered_map<int, vector<string>> memo;
public:
    vector<string> build(string & s, int pos, unordered_set<string> & words ) {
        if(memo.count(pos)) {
            return memo[pos];
        }
        vector<string> ans;
        if(words.count(s.substr(pos)))
            ans.push_back(s.substr(pos));
        for(int i = 0; i + pos < s.size(); ++i) {
            if(words.count(s.substr(pos, i+1))) {
                auto right = build(s, pos + i + 1, words);
                string cur = s.substr(pos, i+1);
                for(auto & s: right) {
                    ans.push_back(cur + " " + s);
                }
            }
        }
        memo[pos] = ans;
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto & x: wordDict) {
            words.insert(x);
        }
        return build(s,0,words);
    }
};
```
TLE
```cpp
struct node {
    bool is_leaf;
    vector<node*> chars;
    node(): is_leaf(false), chars(vector<node*> (26, nullptr)) {}
};


void insert(node * root, const string & s) {
    for(int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 'a';
        if(root->chars[pos] == nullptr)
            root->chars[pos] = new node();
        root = root->chars[pos];
    }
    root->is_leaf = true;
}

class Solution {
    int n;
    vector<vector<string>> values;
public:
    void build(string& s, int pos, node * root, vector<string> & cur) {
        if(pos == s.size()) {
            values.push_back(cur);
            return;
        }
        node * t = root;
        for(int i = pos; i < s.size(); ++i) {
            int p = s[i] - 'a';
            if(t->chars[p]) {
                t = t->chars[p];
                if(t->is_leaf) {
                    string word = s.substr(pos, i - pos + 1);
                    cur.push_back(word);
                    build(s, i+1, root, cur);
                    cur.pop_back();
                }
            }
            else {
                break;
            }
        }
    }
 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        node * root = new node();
        for(auto & word: wordDict) {
            insert(root, word);
        }
        vector<string> cur;
        build(s,0, root, cur);
        vector<string> ans;
        for(auto & v: values) {
            string sentence;
            for(auto & x: v) {
                sentence += x + " ";
            }
            sentence.pop_back();
            ans.emplace_back(sentence);
        }
        return ans;
    }
};
```
