```cpp
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *build(UndirectedGraphNode * root, 
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode*> & m) {
    
    if(!root)
        return nullptr;
    if(m.find(root) == m.end()) {
        UndirectedGraphNode * new_root = new UndirectedGraphNode(root->label);
        m[root] = new_root;
        for(int i = 0; i < root->neighbors.size(); ++i) {
            new_root->neighbors.push_back(build(root->neighbors[i], m));
        }
        return new_root;
    }
    else {
        return m[root];
    }
    
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    return build(node, m);
}
```

```cpp

UndirectedGraphNode * build(UndirectedGraphNode * node, 
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> & mapping) {
    if(!node) {
        return nullptr;
    }
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    mapping[node] = root;
    for(auto x: node->neighbors) {
        if(mapping.find(x) != mapping.end()) {
            root->neighbors.push_back(mapping[x]);
        }
        else {
            root->neighbors.push_back(build(x, mapping));
        }
    }
    return root;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
    return build(node, mapping);
}
```
