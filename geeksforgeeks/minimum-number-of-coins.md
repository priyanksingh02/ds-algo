```cpp
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> notes {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        for(int i = (int)notes.size() - 1; i >= 0 && N > 0; i--) {
            if(N >= notes[i]) {
                ans.push_back(notes[i]);
                N -= notes[i];
                 ++i; // recheck this note
            }
        }
        return ans;
    }
};
```

