```cpp
struct node {
    bool isleaf;
    vector<node*> chars;
    node(): isleaf(false), chars(vector<node*> (26, nullptr)) {}
};

void insert(const string & s, node * root) {
    for(int i = 0; i < s.size(); ++i) {

        int pos = s[i] - 'a';
        if(root->chars[pos] == nullptr)
            root->chars[pos] = new node();
        root = root->chars[pos];
    }
    root->isleaf = true;
}

class StreamChecker {
    node * root;
    string word;
public:
    StreamChecker(vector<string>& words) {
        root = new node();
        for(auto w: words) {
            reverse(w.begin(), w.end());
            insert(w, root);
        }
    }
    
    bool query(char letter) {
        bool ans = false;
        word += letter;
        node * t = root;
        for(int i = word.size() - 1; i >= 0; --i) {
            int pos = word[i] - 'a';
            if(t->chars[pos]) {
                t = t->chars[pos];
                if(t->isleaf) {
                    ans = true;
                    break;
                }
            }
            else {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
 ```
