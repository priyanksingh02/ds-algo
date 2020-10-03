```cpp
struct node {
    bool is_leaf;
    vector<node*> chars;
    node(): is_leaf(false), chars(vector<node*>(26, nullptr)) {}
};

class Trie {
    node * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node * iter = root;
        for(int i = 0; i < word.size(); ++i) {
            int pos = word[i] - 'a';
            if(!iter->chars[pos])
                iter->chars[pos] = new node();
            iter = iter->chars[pos];
        }
        iter->is_leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node * iter = root;
        for(int i = 0; i < word.size() && iter; ++i) {
            int pos = word[i] - 'a';
            iter = iter->chars[pos];
        }
        if(iter && iter->is_leaf)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node * iter = root;
        for(int i = 0; i < prefix.size() && iter; ++i) {
            int pos = prefix[i] - 'a';
            iter = iter->chars[pos];
        }
        if(iter)
            return true;
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 ```
