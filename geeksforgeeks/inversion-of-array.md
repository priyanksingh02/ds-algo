Merge Sort Approach
Time: O(N log N)
Space: O(N)
```cpp
using ll = long long;
ll merge(ll arr[], int low, int mid, int high) {
    int s1 = mid - low + 1;
    int s2 = high - mid;
    ll left[s1], right[s2];
    for(int i = 0; i < s1; ++i) {
        left[i] = arr[low+i];
    }
    for(int i = 0; i < s2; ++i) {
        right[i] = arr[mid+1+i];
    }
    int i = 0, j = 0, k = low;
    int ans = 0;
    while(i < s1 and j < s2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i++];
        }
        else {
            arr[k] = right[j++];
            ans += s1 - i;
        }
        k++;
    }
    while(i < s1) {
        arr[k++] = left[i++];
    }
    while(j < s2) {
        arr[k++] = right[j++];
    }
    return ans;
}

ll merge_sort(ll arr[], int low, int high) {
    ll ans = 0;
    if(low < high) {
        int mid = low + (high - low)/2;
        ans += merge_sort(arr, low, mid);
        ans += merge_sort(arr, mid+1, high);
        ans += merge(arr, low, mid, high);
    }
    return ans;
}

ll inversionCount(ll arr[], ll N) {
    return merge_sort(arr, 0, N-1);
}

```

Binary Tree Approach
Time: O(N log N)
Space: O(N)
```cpp
using ll = long long;
struct node {
    ll val;
    ll small;
    node * left;
    node * right;
    node(ll v): val(v), small(0), left(nullptr), right(nullptr) {}
};

ll insert(node * root, ll key) {
    bool connected = false;
    ll count = 0;
    while(!connected) {
        if(root->val >= key) {
            root->small++;
            if(root->left) {
                root = root->left;
            }
            else {
                root->left = new node(key);
                connected = true;
            }
        }
        else {
            count += root->small + 1;
            if(root->right) {
                root = root->right;
            }
            else {
                root->right = new node(key);
                connected = true;
            }
        }
    }
    return count;
}
long long int inversionCount(long long arr[], long long N)
{
    ll ans = 0;
    node * root = new node(arr[N-1]);
    for(int i = N-2; i >= 0; --i) {
        ans += insert(root, arr[i]);
    }
    return ans;
}
```

STL Approach (TLE)
Time : O(N^2) (distance takes O(N) time)
Space: O(N)
```cpp
long long int inversionCount(long long arr[], long long N) {
    multiset<long long> ms;
    long long ans = 0;
    for(int i = 0; i < N; ++i) {
        ans += distance(ms.upper_bound(arr[i]), ms.end());
        ms.insert(arr[i]);
    }
    return ans;
}

```
