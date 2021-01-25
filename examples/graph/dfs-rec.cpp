#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for(auto i: adj[x]) {
        if(!visited[i])
            dfs(i);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i= 0; i < n; ++i) {
        vector<int> row;
        for(int j= 0; j < n; ++j) {
            int item;
            cin >> item;
            if( item) {
                row.push_back(j);
            }
        }
        adj.push_back(row);
    }
    visited = vector<bool>(n, false);
    cout << visited.size() << endl;
    dfs(0);
    cout << endl;
}
