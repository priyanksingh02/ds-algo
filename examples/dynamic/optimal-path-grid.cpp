// In an n x n grid, find a path with largest possible sum
// Only allowed direction: down and right
// grid contains positive numbers
// 3 7 9 2  7
// 9 8 3 5  5
// 1 7 9 8  5
// 3 8 6 4 10
// 6 3 9 7  8
// Ans: 67 : 3 9 8 7 9 8 5 10 8

// recursive formula : sum(x,y) = max(sum(x-1, y), sum(x, y-1)) + grid[x][y];
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    int grid[][5] = {
        3,7,9,2,7, 9,8,3,5,5, 1,7,9,8,5, 3,8,6,4,10, 6,3,9,7,8
    };

    int values[n+1][n+1] = {0};

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j ) {
            values[i][j] = max(values[i-1][j],values[i][j-1]) + grid[i-1][j-1];
        }
    }

    cout << values[n][n] << endl; // 67
}

