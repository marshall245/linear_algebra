#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrixPtr init_matrix(unsigned long rows, unsigned long cols) {
  size_t ix;
  matrixPtr R = (matrixPtr) malloc(sizeof(matrixPtr));

  (R->rows) = rows;
  (R->cols) = cols;
  (R->array) = (double **) malloc(rows * sizeof(double *));
  for (ix=0; ix<rows; ix++) {
    (R->array)[ix] = malloc(cols * sizeof(double));
  }
  return R;
}

matrixPtr zeros(unsigned long rows, unsigned long cols) {
  matrixPtr R = init_matrix(rows, cols);
  size_t i, j;
  
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      (R->array)[i][j] = 0;
    }
  }
  return R;
}

matrixPtr ones(unsigned long rows, unsigned long cols) {
  matrixPtr R = init_matrix(rows, cols);
  size_t i, j;

  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      (R->array)[i][j] = 1;
    }
  }
  return R;
}

matrixPtr eye(unsigned long n) {
  matrixPtr R = init_matrix(n, n);
  size_t i, j;

  for (i=0; i<(R->rows); i++) {
    for (j=0; j<(R->cols); j++) {
      if (i == j) {
	(R->array)[i][j] = 1;
      } else {
	(R->array)[i][j] = 0;
      }
    }
  }
  return R;
}

matrixPtr randmat(unsigned long rows, unsigned long cols, int modulus, unsigned long seed) {
  matrixPtr R = init_matrix(rows, cols);
  size_t i, j;
  srand(seed);

  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      (R->array)[i][j] = (double) (rand() % modulus);
    }
  }
  return R;
}

void simple_print(matrixPtr aPtr) {
  size_t i, j;
  puts("");
  for (i=0; i<(aPtr->rows); i++) {
    for (j=0; j<(aPtr->cols); j++) {
      printf("%8.2g ", (aPtr->array)[i][j]);
    }
    puts("");
  }
  puts("");
}

void big_print(matrixPtr aPtr) {
  if ((aPtr->rows<7) && (aPtr->cols<7)) {
    simple_print(aPtr);
    return;
  }
  size_t i, j;
  unsigned long rmax, cmax;
  rmax = aPtr->rows;
  cmax = aPtr->cols;
  puts("");
  for (i=0; i<aPtr->rows; i++) {
    for (j=0; j<aPtr->cols; j++) {
      if ((i < 3) || (i > rmax - 4)) {
	if ((j < 3) || (j > cmax - 4)) {
          printf("%8.2g ", (aPtr->array)[i][j]);
        } else if ((j > 2) && (j < 6)) {
          printf("%s", " . ");
        }
      } else if (((i > 2) && (i < 6)) && ((j == 0))) {
        printf("%s", "          .                               .\n");
      }
      if ((j == cmax-1) && ((i < 6) || (i > rmax - 4))) {
        puts("");
      }
    }
    
  }
} 
