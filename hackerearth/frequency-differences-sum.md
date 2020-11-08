```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin >> a;
	int freq[30] = {0};
	int ans = 0;
	for(int i = 0; i < a.size(); ++i) {
		memset(freq, 0, sizeof(freq));
		int maxfreq = 0, minfreq;
		set<pair<int,int>> s;
		for(int j = i; j < a.size(); ++j) {
			int item = a[j] - 'a';
			freq[item]++;
			maxfreq = max(maxfreq, freq[item]);
			if(freq[item] > 1)
				s.erase(s.find(make_pair(freq[item]-1,item)));
			s.insert(make_pair(freq[item],item));
			minfreq = s.begin()->first;
			ans += maxfreq - minfreq;
		}
	}
	cout << ans;
}

```
