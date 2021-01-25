```cpp
int middle(int A, int B, int C){
  if(A > B) {
    if(B > C) return B;
    if(A > C) return C;
    else return A;
  }
  else {
    if(A > C) return A;
    if(B > C) return C;
    else return B;
  }
}
```
