#include <iostream>
#include <queue>
#include <vector>
#include "header.h"
using namespace std;

void bfs(vector<vector<int>> & adj) {
    int n = adj.size();
    vector<bool> visited (n , false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int p = q.front(); q.pop();
        cout << p << " ";
        for(auto x: adj[p]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj;
    for(int i = 0; i < n; ++i) {
        vector<int> row;
        for(int j= 0; j < n; ++j) {
            int item;
            cin >> item;
            if(item) {
                row.push_back(j);
            }
        }
        adj.push_back(row);
    }
    debug() << imie(adj);
    bfs(adj);
    cout << endl;
}
