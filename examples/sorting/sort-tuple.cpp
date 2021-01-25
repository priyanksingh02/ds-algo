#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

int main() {
    vector<tuple<int,int,int>> locations;
    locations.push_back({1,3,4});
    locations.push_back({5,1,7});
    locations.push_back({1,3,9});
    locations.push_back({1,0,4});

    sort(begin(locations),end(locations));
    for(auto x: locations) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x)<< endl;
    }
}

