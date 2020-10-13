```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<pair<vector<NestedInteger>, int>> st;
    int nxt;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push({nestedList, 0});
        
    }
    
    int next() {
        return nxt;
    }
    
    bool hasNext() {
        while(!st.empty()) {
            if(st.top().first.size() == st.top().second)
                st.pop();
            else {
                auto ni = st.top().first[st.top().second++];
                if(ni.isInteger()) {
                    nxt = ni.getInteger();
                    return true;
                }
                else {
                    st.push({ni.getList(), 0});
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 ```
