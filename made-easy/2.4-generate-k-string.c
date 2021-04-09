#include <stdio.h>
#include <stdlib.h>

int arr[10];

void print(int * arr, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void gen(int pos, int n, int k) {
  if(pos == n) {
    print(arr, n);
    return;
  }
  for(int i = 0; i < k; ++i) {
    arr[pos] = i;
    gen(pos+1, n, k);
  }
}

int main(int argc, char * argv[]) {
  if(argc!=3) {
    printf("Usage: %s <N> <K>\nN should be less than 10\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int N = atoi(argv[1]);
  int K = atoi(argv[2]);
  if( N >= 10) return 1;
  gen(0, N, K);
}
