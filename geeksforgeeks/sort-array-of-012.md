```cpp
void sort012(int a[], int n)
{
    int zero = 0, two = n-1;
    for(int i = zero; i <= two; ++i) {
        if(a[i] == 0) {
            swap(a[i], a[zero++]);
        }
        else if(a[i] == 2) {
            swap(a[i], a[two--]);
            --i; // observe the current element again
        }
    }
    for(int i = zero; i <= two; ++i) {
        a[i] = 1;
    }
}
```

