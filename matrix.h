#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
  unsigned long rows;
  unsigned long cols;
  double ** array;
} Matrix;

typedef Matrix * matrixPtr;

#endif
