```cpp
#include <bits/stdc++.h>
using namespace std;

long largest(vector<int> & num, int k) {
	long ans = 0, cur = 0;
	for(int i = 0; i < k; ++i) {
		cur += num[i];
	}
	ans = max(ans, cur);
	for(int i = k; i < num.size(); ++i) {
		cur -= num[i-k];
		cur += num[i];
		ans = max(ans, cur);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long N, X;
	cin >> N >> X;
	vector<int> num(N);
	for(int &x: num) cin >> x;
	long low = 1, high = N;
	long ans = 0;
	while(low <= high) {
		long mid = low + (high - low)/2;
		if(largest(num, mid) <= X) {
			ans = mid;
			low = mid + 1;
		}
		else 
			high = mid - 1;
	}
	cout << ans << "\n";
}
```
