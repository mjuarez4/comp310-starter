#include <stdio.h>
#include <stdlib.h>

int factorial(num){
  if (num == 0){
    return 1;
  }
  return num * factorial(num - 1);
}

int main(void){
  int num = 5;
  printf("The factorial of %d is %d\n", num, factorial(num));
}

