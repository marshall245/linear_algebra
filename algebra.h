#ifndef ALGEBRA_H
#define ALGEBRA_H
#include "matrix.h"
#include "base.h"

// from algebra.c
matrixPtr add(matrixPtr, matrixPtr);
matrixPtr scale(double a, matrixPtr A);
matrixPtr multiply(matrixPtr A, matrixPtr B);
matrixPtr transpose(matrixPtr);



#endif
