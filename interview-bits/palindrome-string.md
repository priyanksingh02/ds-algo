```cpp

int Solution::isPalindrome(string A) {
    int i = 0;
    int j = (int)A.size();
    while(i < j) {
        if(!isalnum(A[i])) {
            i++;
            continue;
        }
        if(!isalnum(A[j])) {
            j--;
            continue;
        }
        if(tolower(A[i]) != tolower(A[j]))
            return false;
        i++;
        j--;
    }
    return true;
}
```
