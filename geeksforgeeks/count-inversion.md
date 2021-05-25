```cpp
long long merge(long long arr[], int l,int m, int h) {
  int n1 = m - l + 1;
  int n2 = h - m;
  long long * a = new long long[n1];
  long long * b = new long long[n2];
  for(int i = 0; i < n1; ++i) {
    a[i] = arr[l+i];
  }
  for(int i = 0; i < n2; ++i) {
    b[i] = arr[m+1+i];
  }
  int k = l, i = 0, j = 0;
  long long count = 0;
  while(i < n1 && j < n2) {
    if(a[i] <= b[j]) {
      arr[k] = a[i++];
    }
    else {
      arr[k] = b[j++];
      count += n1 - i;
    }
    k++;
  }

  while(i < n1) {
    arr[k++] = a[i++];
  }

  while(j < n2) {
    arr[k++] = b[j++];
  }

  delete a, b;
  return count;
}

long long merge_sort(long long arr[], int l, int h) {
  if(l < h) {
    int m = l + (h-l)/2;
    long long ans = 0;
    ans += merge_sort(arr, l , m);
    ans += merge_sort(arr, m+1, h);
    ans += merge(arr, l, m, h);
    return ans;
  }
  return 0;
}
void print(long long arr[], int N) {
  for(int i =0;i <N; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
long long inversionCount(long long arr[], long long N) {
  // print(arr, N);
  long long ans =  merge_sort(arr, 0, N-1);
  // print(arr, N);
  return ans;
}

```
