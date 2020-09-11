```cpp
int Solution::isPalindrome(int A) {
    if(A < 0)
        return false;
    int rev  = 0;
    int t = A;
    while(t) {
        int next = rev*10 + (t%10);
        if(next < rev)
            return false; //overflow
        rev = next;
        t /= 10;
    }
    return rev == A;
}
```
