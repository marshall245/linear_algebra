#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "base.h"

matrixPtr add(matrixPtr A, matrixPtr B) {
  if ((A->rows != B->rows) || (A->cols != B->cols)) {
    printf("%s", "Dimensions do not match for A, B");
    exit(1);
  }
  size_t i, j;
  matrixPtr R = init_matrix(A->rows, A->cols);
  for (i=0; i<A->rows; i++) {
    for (j=0; j<A->cols; j++) {
      (R->array)[i][j] = (A->array)[i][j] + (B->array)[i][j];
    }
  }
  return R;
}

matrixPtr scale(double a, matrixPtr A) {
  size_t i, j;
  matrixPtr R = init_matrix(A->rows, A->cols);
  
  for (i=0; i<R->rows; i++) {
    for (j=0; j<R->cols; j++) {
      (R->array)[i][j] = a * (A->array)[i][j];
    }
  }
  return R;
}

matrixPtr multiply(matrixPtr A, matrixPtr B) {
  if (A->cols != B->rows) {
    printf("%s", "A and B have mismatched dimensions");
    exit(1);
  }
  size_t i, j, k;
  matrixPtr R = init_matrix(A->rows, B->cols);

  for (i=0; i<R->rows; i++) {
    for (j=0; j<R->cols; j++) {
      (R->array)[i][j] = 0;
      for (k=0; k<A->cols; k++) {
	(R->array)[i][j] += (A->array)[i][k] * (B->array)[k][j];
      }
    }
  }
  return R;
}

matrixPtr transpose(matrixPtr A) {
  size_t i, j;
  matrixPtr R = init_matrix(A->cols, A->rows);
  
  for (j=0; j<R->rows; j++) {
    for (i=0; i<R->cols; i++) {
      (R->array)[j][i] = (A->array)[i][j];
    }
  }
  return R;
}
