#include <iostream>
#include "header.h"
#include <stack>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> & adj) {
    int n = adj.size() ;
    vector<bool> visited (n , false);
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while(!s.empty()) {
        int p = s.top();
        cout << p << " ";
        s.pop();
        for(auto x: adj[p]) {
            if(!visited[x]) {
                visited[x] = true;
                s.push(x);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj (n);
    for(int i = 0; i < n; ++i) {
        for( int j = 0; j < n; ++j) {
            int item;
            cin >> item;
            if(item) {
                adj[i].push_back(j);
            }
        }
    }
    debug() << imie(adj);
    dfs(adj);
    cout << endl;
}
