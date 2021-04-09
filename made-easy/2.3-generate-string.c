#include <stdio.h>
#include <stdlib.h>

void generate(char * arr, int pos, int n) {
  if(pos == n) {
    arr[pos] = '\0';
    printf("%s\n", arr);
    return;
  }
  arr[pos] = '0';
  generate(arr, pos+1, n);
  arr[pos] = '1';
  generate(arr, pos+1, n);
}

int main(int argc, char * argv[]) {
  if(argc != 2) {
    printf("Usage: %s <N>\n",argv[0]);
    printf("N should be less than 7\n");
    exit(EXIT_FAILURE);
  }
  int N = atoi(argv[1]);
  if(N >= 7) return 1;
  char * arr = (char *)malloc((N+1)*sizeof(char));
  generate(arr, 0, N);
  
}
