```cpp
#include <bits/stdc++.h>
using namespace std;

bool solve(string & s) {
  vector<int> freq(26, 0);
  for(char c: s) {
    freq[c-'a']++;
  }
  priority_queue<pair<int, char>> pq;
  for(int i =0;i < freq.size(); ++i) {
    if(freq[i] > 0) {
      pq.push({freq[i], i+'a'});
    }
  }
  while(pq.size() >= 2) {
    char c1, c2; int f1, f2;
    c1 = pq.top().second; f1 = pq.top().first; pq.pop();
    c2 = pq.top().second; f2 = pq.top().first; pq.pop();
    if(f1 > 1) pq.push({f1-1, c1});
    if(f2 > 1) pq.push({f2-1, c2});
  }
  if(pq.size() == 1 && pq.top().first > 1)
    return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string input;
    cin>>input;
    cout << solve(input) << "\n";
  }
}

```
