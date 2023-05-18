#include <stdio.h>

#define N 1000

void matrix_multiply(int A[N][N], int B[N][N], int C[N][N]) {
  int i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      C[i][j] = 0;
    }
  }

  for (i = 0; i < N; i++) {
    for (k = 0; k < N; k++) {
      for (j = 0; j < N; j += 4) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j + 1] += A[i][k] * B[k][j + 1];
        C[i][j + 2] += A[i][k] * B[k][j + 2];
        C[i][j + 3] += A[i][k] * B[k][j + 3];
      }
    }
  }
}

int main() {
  int A[N][N], B[N][N], C[N][N];
  // Initialize A and B matrices

  matrix_multiply(A, B, C);

  return 0;
}