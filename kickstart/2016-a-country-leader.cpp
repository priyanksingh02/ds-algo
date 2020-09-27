#include <bits/stdc++.h>
using namespace std;

int count(string & str) {
  unordered_set<char> s;
  for(auto & c: str) {
    if( c != ' ')
      s.insert(c);
  }
  return s.size();
}

void solve() {
  int n;
  cin >> n;
  cin.ignore();
  string ans;
  int m = 0;
  while(n--) {
    string in;
    getline(cin, in);
    int c = count(in);
    if( c > m ) {
      m = c;
      ans = in;
    }
    else if(c == m && in < ans)
      ans = in;
  }
  cout << ans << "\n";
}

int main() {
  int tlim;
  cin >> tlim;
  for(int i = 1; i <= tlim; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
