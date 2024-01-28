#include <stdio.h>
#include <stdlib.h>

//I used chatgpt 4 for help with understanding static variables using define
//and to refresh my memory on matrix multiplication rules. I also used chaptgpt 4
//to help with padding and formating (so that the numbers would print in rows/columns) evenly
void addMatrices(int r, int c, int a[r][c], int b[r][c], int sum[r][c]){
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      sum[i][j] = a[i][j] + b[i][j];
    }
  }
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int a[r1][c1], int b[r2][c2], int product[r1][c2]){
  for (int i = 0; i < r1; i++){
    for (int j = 0; j < c2; j++){
      product[i][j] = 0;
      for (int k = 0; k < c1; k++){
        product[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void printMatrix(int r, int c, int matrix[r][c]){
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

#define r1 2
#define c1 2
#define r2 2
#define c2 2
#define r3 3
#define c3 3
int main(void){
  int matrix1[r1][c1] = {{1,2}, {3,4}};
  int matrix2[r2][c2] = {{5,6}, {7,8}};
  int matrix3[r3][c3] = {{1,2,3}, {4,5,6}, {7,8,9}};

   int sum[r1][c1];
   int product[r1][c2];
  if (r1 == r2 || c1 == c2){
    addMatrices(r1, c1, matrix1, matrix2, sum);
    printf("Matrix Addition:\n");
    printMatrix(r1, c1, sum);
    
  } else {
    printf("These matrices are not the same size and cannot be added.");
  }
  if (c1 == r2){
    multiplyMatrices(r1, c1, r2, c2, matrix1, matrix2, product);
    printf("Matrix Multiplication:\n");
    printMatrix(r1, c2, product);
  } else {
    printf("These matrices do not have complying dimensions and cannot be multiplied.");
  }
  return 0;
}

