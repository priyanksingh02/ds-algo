```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> num(n);
	for(int &x: num)
		cin >> x;
	sort(num.begin(), num.end());
	int q;
	cin >> q;
	int pos, a, b;
	while(q--) {
		cin >> a >> b;
		if(a) {
			pos = upper_bound(num.begin(), num.end(), b) - num.begin();
		}
		else {
			pos = lower_bound(num.begin(), num.end(), b) - num.begin();
		}
		cout << n - pos << "\n";
	}
}
```
