#include <stdio.h>
#include "matrix.h"
#include "algebra.h"
#include "base.h"

int main(int argc, char * argv[]) {

  unsigned long row, col;
  matrixPtr zPtr, iPtr, onePtr, randPtr;
  row = atoi(argv[1]);
  col = atoi(argv[2]);
  
  randPtr = randmat(row, col, 1000, time(NULL));

  big_print(randPtr);
  big_print(transpose(randPtr));
  big_print(multiply(transpose(randPtr), randPtr));

  return 0;
}
