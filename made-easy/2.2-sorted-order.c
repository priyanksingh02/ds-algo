#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool check_sorted(int * arr, int n) {
  if( n <= 2) 
    return true;
  if(!check_sorted(arr, n-1))
    return false;
  return ((arr[n-1] >= arr[n-2]) && (arr[n-2] >= arr[n-3])) || 
    ((arr[n-1] <= arr[n-2]) && (arr[n-2] <= arr[n-3]));
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  assert(n > 0);
  assert(check_sorted(arr, n) == true);
  int arr2[] = { 4, 2, 1, 3 };
  n = sizeof(arr2)/sizeof(arr2[0]);
  assert(check_sorted(arr2, n) == false);
  int arr3[] = { 4, 3, 2, 1 };
  n = sizeof(arr3)/sizeof(arr3[0]);
  assert(check_sorted(arr3, n) == true);
}
