```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n;
	vector<double> r(n);
	for(int i = 0; i < n; ++i) {
		long a, b;
		cin >> a >> b;
		double radius = a*a + b*b;
		r[i] = sqrt(radius);
	}
	sort(r.begin(), r.end());
	// for(auto & x: r) cout << x << " "; cout << endl;
	cin >> q;
	while(q--) {
		long radius;
		cin >> radius;
		long cnt = upper_bound(r.begin(), r.end(), radius) - r.begin();
		cout << cnt << "\n";
	}
}
```
