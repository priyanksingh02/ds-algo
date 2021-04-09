#include <stdio.h>
#include <stdlib.h>

/*
 * n : Number of discs
 * A : Source
 * C : Destination
 */
int tower_of_hanoi(int n, char A, char B, char C) {
  if( n == 1 ) {
    printf("Move from %c to %c\n", A, C);
    return 1;
  }
  int ans = tower_of_hanoi(n-1, A, C, B);
  printf("Move from %c to %c\n", A, C);
  ans++;
  ans += tower_of_hanoi(n-1, B, A, C);
  return ans;
}

int main(int argc, char * argv[]) {
  if(argc != 2) {
    printf("Usage: %s <number_of_discs>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int move_count = tower_of_hanoi(atoi(argv[1]),'A','B','C');
  printf("Total Moves = %d\n", move_count);

}
