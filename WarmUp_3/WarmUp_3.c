#include <stdio.h>

int main(void){
  int arr[5] = {1, 2, 3, 4, 5};
  int sum  = 0;
  double len = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < len; i++){
    sum += arr[i];
  }
  double average = sum / len;
  printf("Sum: %d\n", sum);
  printf("Average: %f\n", average);
  return 0;
}
