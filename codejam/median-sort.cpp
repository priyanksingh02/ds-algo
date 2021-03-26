#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c) {
  int ans;
  cout << a << ' ' << b << ' ' << c << endl;
  cin >> ans;
  return ans;
}

int submit_answer(vector<int> & arr) {
  for(int i = 0; i < (int)arr.size(); ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}

void shift(vector<int>& arr, int l, int r) {
  assert(l >= 0 && r < (int)arr.size());
  int tmp = arr[r];
  for(int i = r; i > l; --i) {
    arr[i] = arr[i-1];
  }
  arr[l] = tmp;
}

void print(vector<int>& arr) {
  for(int i = 0;i  < (int)arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int t, n, q;
  cin >> t >> n >> q;
  vector<int> arr(n);
  while(t--) {
    for(int i = 0; i < n; ++i) {
      arr[i] = i+1;
    }
    for(int k = 2; k < n; ++k) {
      int l = 0, r = k - 2;
      //cout << "Arr: ";
      //print(arr);
      while(l <= r) {
        int mid = l + (r-l)/2;
        //cout << "query " << l << ' ' << mid << ' ' << r << endl;
        int ans = query(arr[mid], arr[mid+1], arr[k]);
        //cout << "ans received " << ans << endl;
        if(ans == arr[k]) {
          //cout << "mid" << endl;
          shift(arr, mid+1, k);
          break;
        }
        else if(ans == arr[mid+1]) {
          //cout << "right" << endl;
          l = mid + 1;
        }
        else if(ans == arr[mid]) {
          //cout << "left" << endl;
          if(l == mid) {
            //cout << "left + mid" << endl;
            shift(arr, mid, k);
          }
          r = mid - 1;
        }
        else { 
          assert(false);
        }
      }
    }
    if(submit_answer(arr) != 1) {
      exit(0);
    }
  }
}
