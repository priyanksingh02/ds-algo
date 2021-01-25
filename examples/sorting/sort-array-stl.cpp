#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int arr[] = { 2, 5, 3, 1, -2, 3, 7, 6};
    int n = sizeof arr / sizeof arr[0];
    for(auto x: arr) cout << x << " ";
    cout << endl;
    sort(arr, arr+n);
    for(auto x: arr) cout << x << " ";
    cout << endl;
}

