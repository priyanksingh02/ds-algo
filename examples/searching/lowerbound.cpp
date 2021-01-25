#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerbound(vector<int> & arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    int best = -1;
    while(start <= end) {
        int mid = start + ((end-start) >> 1);
        if(arr[mid] <= key) {
            best = mid;
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return best;
}

int r(int a, int b) {
    return rand()%(b-a+1) + a;
}

int main() {
    int n = 15;
    vector<int> v(n);
    for(auto & x: v)
        x = r(2,20);
    sort(v.begin(),v.end());
    for(auto x: v)
        cout << x << " ";
    cout << endl;
    vector<int> keys { 0, 6, 9, 12, 15, 10, 25};
    for(auto key:keys) {
        cout << "lowerbound for " << key << " = ";
        auto pos = lowerbound(v,key);
        if(pos >= 0 and pos < (int)v.size())
            cout << v[pos] ;
        cout << " (@ " << pos << " )" << endl;
    }
}
