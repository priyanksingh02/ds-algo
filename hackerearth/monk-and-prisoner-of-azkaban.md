```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long> num(n);
	for(long & x: num) cin >> x;
	vector<long> X(n), Y(n);
	stack<int> st;
	for(int i = 0; i < n; ++i) {
		while(!st.empty() and num[st.top()] <= num[i])
			st.pop();
		if(st.empty())
			X[i] = -1;
		else
			X[i] = st.top() + 1;
		st.push(i);
	}
	while(!st.empty())
		st.pop();
	for(int i = n - 1; i>= 0; --i) {
		while(!st.empty() and num[st.top()] <= num[i])
			st.pop();
		if(st.empty())
			Y[i] = -1;
		else
			Y[i] = st.top() + 1;
		st.push(i);
	}
	for(int i = 0; i < n; ++i) {
		cout << X[i] + Y[i] << " ";
	}
}

```
