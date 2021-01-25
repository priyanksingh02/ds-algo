#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct cycle_exception {
    cycle_exception(string e) {}
};

int n;
int status[1000];
vector<int> result;
vector<int> adj[1000]; //adjlist

void sort(int u) {
    status[u] = 1;
    for(auto v: adj[u]) {
        if(status[v] == 1)
            throw cycle_exception("Cycle exists!");
        if(status[v] == 0)
            sort(v);
    }
    status[u] = 2;
    result.push_back(u);
}

vector<int> parse_input(string & in) {
    stringstream s {in};
    int num;
    vector<int> result;
    while(s >> num) {
        if(num != -1) {
            result.push_back(num-1);
        }
        else break;
    }
    return result;
}

int main() {
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i) {
        string input;
        getline(cin, input);
        adj[i] = parse_input(input);
    }

    //for(int i = 0; i < n; ++i) {
    //    for(auto x: adj[i]) {
    //        cout << x << " ";
    //    }
    //    cout << endl;
    //}

    memset(status, 0, sizeof status);

    for(int i = 0; i < n; ++i) {
        if(status[i] == 0) {
            sort(i);
        }
    }
    reverse(begin(result), end(result));

    for(auto x: result) {
        cout << x + 1 << " ";
    }
    cout << endl;

}
