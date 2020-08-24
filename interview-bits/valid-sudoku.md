````cpp
int Solution::isValidSudoku(const vector<string> &A) {
    int row[9] = {0}, col[9] = {0}, box[3][3] = {0};
    auto mark = [&](int i, int j, int num) {
        row[i] |= 1 << num;
        col[j] |= 1 << num;
        box[i/3][j/3] |= 1 << num;
    };
    auto taken = [&](int i, int j, int num) {
        int pos = 1 << num;
        return (row[i] & pos) || (col[j] & pos) || (box[i/3][j/3] & pos);
    };
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < A.size(); ++j) {
            if(A[i][j] != '.') {
                int num = A[i][j] - '0';
                if(taken(i,j,num))
                    return false;
                else {
                    mark(i,j,num);
                }
            }   
        }
    }
    return true;
}
```

```cpp
bool taken(int & num, int pos) {
    return num & (1 << pos);
}

void mark(int & num, int pos) {
    num |= (1 << pos);
}
int Solution::isValidSudoku(const vector<string> &A) {
    int row[9] = {0};
    int col[9] = {0};
    int box[3][3] = {0};
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        for(int j =0; j < n; ++j) {
            if(A[i][j] != '.') {
                int pos = A[i][j] - '0';
                if(taken(row[i],pos) || taken(col[j],pos) || taken(box[i/3][j/3],pos))
                    return 0;
                mark(row[i],pos);
                mark(col[j],pos);
                mark(box[i/3][j/3],pos);
            }
        }
    }
    return 1;
}
```
