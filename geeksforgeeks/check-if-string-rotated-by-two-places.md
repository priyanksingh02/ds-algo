```cpp
bool isRotated(string str1, string str2)
{
    // Your code here
    string left = str1;
    string right = str1;
    int n = str1.size();
    if(n != str2.size())
        return false;
    int k = 2;
    k %= n;
    // left rotation
    reverse(left.begin(), left.begin() + k);
    reverse(left.begin() + k, left.end());
    reverse(left.begin(), left.end());
    if(left == str2)
        return true;
    k = (n - 2)%n;
    if(k < 0) k += n;
    // right rotation
    reverse(right.begin(), right.begin() + k);
    reverse(right.begin() + k, right.end());
    reverse(right.begin(), right.end());
    if(right == str2)
        return true;
    return false;
}

```

