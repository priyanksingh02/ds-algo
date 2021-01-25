#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> names = {"hi", "joe", "alice", "bob", "mallery", "zoe"};
    sort(begin(names), end(names),
            [](const string& a, const string &b){
                if(a.size() == b.size()) return a < b;
                else return a.size() < b.size();
            });
    for(auto name: names) {
        cout << name << "\n";
    }
}
