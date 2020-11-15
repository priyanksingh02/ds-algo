Time: O(N) (Single pass bubble sort)
```cpp
void zigZag(int arr[], int n) {
    bool d = true;
    for(int i = 0; i+1 < n; ++i) {
        if(d && arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
        else if(!d && arr[i] < arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
        d^= true;
    }
}
```

