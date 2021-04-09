#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h> // MAX: part of GNU library

int region_size(char mat[][6], int n, int x, int y) {
  if(x < 0 || y < 0 || x >= n || y >= n || mat[x][y] == '0')
    return 0;
  int count = 1;
  mat[x][y] = '0';
  for(int i = -1; i < 2; ++i) {
    for(int j = -1; j < 2; ++j) {
      if(i == 0 && j == 0) continue;
      count += region_size(mat, n, x + i, y + j);
    }
  }
  return count;
}

int main() {

  int n = 5;
  char mat[][6] = {
    "11000",
    "01100",
    "00101",
    "10001",
    "01011"
  };
  // Answer is 5

  int max_count = 0;

  for(int i= 0;i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(mat[i][j] == '1') {
        int count = region_size(mat, n, i, j);
        max_count = MAX(count, max_count);
      }
    }
  }

  printf("Max Count is %d\n",max_count);

}
