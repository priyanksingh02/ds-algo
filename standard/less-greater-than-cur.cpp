#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// TODO : optimal way to find number of elements greater as well as less than current element lying to the left side

// vector<int> less_than_cur(vector<int> &arr) {
//   stack<int> st;
//   vector<int> ans;
//   for(int i = 0; i < (int)arr.size(); ++i) {
//     while(!st.empty() and st.top() >= arr[i])
//       st.pop();
//     st.push(arr[i]);
//     ans.push_back((int)st.size() - 1);
//   }
//   return ans;
// }

// vector<int> more_than_cur(vector<int> &arr) {
//   stack<int> st;
//   vector<int> ans;
//   for(int i = 0; i < (int)arr.size(); ++i) {
//     while(!st.empty() and st.top() <= arr[i])
//       st.pop();
//     st.push(arr[i]);
//     ans.push_back((int)st.size() - 1);
//   }
//   return ans;
// }

void print(const vector<int> & arr) {
  for(auto & x: arr)
    cout << x << " ";
  cout << endl;
}

int main() {
  vector<int> arr { 4, 2, 7, 1, 8, 3, 7, 2, 1, 0, 9 };
  cout << "ORG:  ";
  print(arr);
  cout << "MORE: ";
  // print(more_than_cur(arr));
  cout << "LESS: ";
  // print(less_than_cur(arr));
}
