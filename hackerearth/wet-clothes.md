```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, g;
	cin >> n >> m >> g;
	vector<int> t(n);
	for(int & x: t)
		cin >> x;
	vector<int> dur(m);
	for(int & x: dur)
		cin >> x;
	int max_dur = 0;
	for(int i = 1; i < n; ++i) {
		max_dur = max(max_dur, t[i] - t[i-1]);
	}
	int cnt = 0;
	for(int i = 0;i < m; ++i) {
		if(dur[i] <= max_dur)
			++cnt;
	}
	cout << cnt ;
}
```
