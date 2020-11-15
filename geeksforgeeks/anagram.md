```cpp
bool isAnagram(string c, string d){
    if(c.size() != d.size())
        return false;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    return c==d;
}
```

