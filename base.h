#ifndef BASE_H
#define BASE_H
#include "matrix.h"

// from base.c
matrixPtr init_matrix(unsigned long, unsigned long);
matrixPtr zeros(unsigned long, unsigned long);
matrixPtr ones(unsigned long, unsigned long);
matrixPtr eye(unsigned long);
matrixPtr randmat(unsigned long, unsigned long, int, unsigned long);
void simple_print(matrixPtr);
void big_print(matrixPtr);
#endif
