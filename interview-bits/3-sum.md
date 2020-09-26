```cpp
int Solution::threeSumClosest(vector<int> &arr, int target) {
  long closest = INT_MAX;
  int ans = 0;
  sort(arr.begin(),arr.end());
  for(int i = 0; i < arr.size(); ++i) {
    int j = i + 1;
    int k = (int)arr.size() - 1;
    long t = target - arr[i];
    while(j < k) {
      long sum = arr[j] + arr[k];
      if(abs(t-sum) < closest) {
        closest = abs(t-sum);
        ans = arr[i]+arr[j]+arr[k];
      }
      if(sum < t) {
        j++;
      }
      else {
        k--;
      }
    }
  }
  return ans;
}
```
