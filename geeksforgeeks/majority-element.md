```cpp
int majorityElement(int a[], int size)
{
    int elem = -1, cnt = 0;
    for(int i = 0;i < size; ++i) {
        if(elem == a[i]) {
            ++cnt;
        }
        else if(elem == -1) {
            elem = a[i];
            cnt = 1;
        }
        else if(--cnt == 0) {
            elem = -1;
        }
    }
    if(elem == -1) return -1;
    cnt = 0;
    for(int i= 0;i < size; ++i) {
        if(a[i] == elem) {
            ++cnt;
        }
    }
    if( cnt > size/2) {
        return elem;
    }
    else {
        return -1;
    }
    
}

```
